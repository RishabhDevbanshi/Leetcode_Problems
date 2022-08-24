class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long> dp(size(questions)+1,-1);
        
        function<long(long)> dfs = [&](int idx)->long{
            if(idx >= size(questions))
                return 0;
            
            if(dp[idx] != -1)
                return dp[idx];
            
            long one = dfs(idx+1);
            long two = questions[idx][0] + dfs(idx + 1 + questions[idx][1]);
            
            return dp[idx] = max(one,two);
        };
        
        return dfs(0);
    }
};