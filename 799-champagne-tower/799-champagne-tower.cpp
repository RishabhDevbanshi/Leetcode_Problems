class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101];
        memset(dp,0,sizeof dp);
        dp[0][0] = poured;
        
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(dp[i][j] >= 1)
                {
                    double val = (dp[i][j] - 1.0)/2.0;
                    
                    dp[i+1][j] += val;
                    dp[i+1][j+1] += val;
                    
                    dp[i][j] = 1;
                }
            }
        }
        
        return dp[query_row][query_glass];
    }
};