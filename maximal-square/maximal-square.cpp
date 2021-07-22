class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        int res = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(matrix[i-1][j-1] == '1')
                    dp[i][j] = 1 + min({dp[i-1][j] ,dp[i-1][j-1] , dp[i][j-1]});
                res = max(res,dp[i][j]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<"\n";
        }
        
        return res*res;
    }
};