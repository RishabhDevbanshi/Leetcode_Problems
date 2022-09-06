class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        
       const int mod = 1e9 + 7; 
        vector<vector<int>> dp(3001,vector<int>(1001,-1));
        
        function<int(int,int)> dfs = [&](int idx,int k){
            if(idx == endPos and k==0)
                return 1;
            if(k == 0)
                return 0;
            
            if(dp[idx+1000][k] != -1)
                return dp[idx+1000][k];
            
            int ans = dfs(idx+1,k-1)%mod;
            if(k-1 >= (-idx + endPos + 1))
                ans = (ans%mod + dfs(idx-1,k-1)%mod)%mod;
            
            return dp[idx+1000][k] = ans;
        };
        
        return dfs(startPos,k)%mod;
    }
};