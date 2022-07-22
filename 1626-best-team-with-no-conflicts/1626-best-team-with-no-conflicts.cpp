class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr(size(ages));
        int maxi = 0;
        
        for(int i=0;i<size(ages);i++)
        {
            arr[i] = {ages[i],scores[i]};
        }
        
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> dp(size(ages)+1 , vector<int>(size(ages)+2,-1));
        
        function<int(int,int)> memo = [&](int idx,int prev){
            if(idx == size(arr))
                return 0;
            
            if(dp[idx][prev] != -1)
                return dp[idx][prev];
            
            if(prev != size(ages) and arr[prev].first < arr[idx].first and arr[prev].second > arr[idx].second)
                return dp[idx][prev] = memo(idx+1,prev);
            if(prev != size(ages) and arr[prev].first == arr[idx].first)
            {
                int op2 = memo(idx+1,prev);
                int op1 = arr[idx].second + memo(idx+1,arr[idx].second > arr[prev].second ? idx : prev);
                
                return dp[idx][prev] = max(op1,op2);
            }
            return dp[idx][prev] = max(memo(idx+1,prev) ,arr[idx].second + memo(idx+1,idx));
        };
        
        return memo(0,size(ages));
    }
};