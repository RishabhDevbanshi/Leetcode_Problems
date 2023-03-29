class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        
        vector<vector<int>> dp(size(satisfaction)+2,vector<int>(size(satisfaction)+1,-1));
        
        function<int(int,int)> dfs = [&](int time,int idx){
            if(idx == size(satisfaction))
                return 0;
            if(dp[time][idx] != -1)
                return dp[time][idx];
            int op1 = dfs(time,idx+1);
            int op2 = time*satisfaction[idx] + dfs(time+1,idx+1);
            
            return dp[time][idx] = max(op1,op2);
        };
        
        return dfs(1,0);
    }
};