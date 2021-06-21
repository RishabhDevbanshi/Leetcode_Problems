class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++) dp[n-1][j] = 1;
        for(int i=0;i<n;i++) dp[i][m-1] = 1;
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};