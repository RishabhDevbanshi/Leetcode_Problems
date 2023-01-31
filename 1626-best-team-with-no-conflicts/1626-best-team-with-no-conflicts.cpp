class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr(size(scores));
        for(int i=0;i<size(scores);i++)
            arr[i] = {ages[i],scores[i]};
        
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> dp(size(arr)+3,vector<int>(size(arr)+3,-1));
        
        function<int(int,int)> dfs = [&](int prev,int idx){
            if(idx == size(arr))
                return 0;
            if(dp[prev+1][idx+1] != -1)
                return dp[prev+1][idx+1];
            int op1 = dfs(prev,idx+1);
            int op2 = 0;
            if(prev == -1 or arr[idx].first == arr[prev].first or arr[idx].second >= arr[prev].second)
                op2 = arr[idx].second + dfs(idx,idx+1);
            return dp[prev+1][idx+1] = max(op1,op2);
        };
        
        
        return dfs(-1,0);
    }
};