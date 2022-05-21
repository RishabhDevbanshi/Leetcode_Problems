class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[size(coins)+1][amount+1];
        memset(dp,0,sizeof dp);
        
        for(int i=0;i<size(coins);i++)
            dp[i][0] = 0;
        for(int i=1;i<=amount;i++)
            dp[0][i] = 1000000;
        
        for(int i=1;i<=size(coins);i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(dp[i-1][j],1 + dp[i][j - coins[i-1]]);
            }
        }
        
        // for(auto )
        
        return dp[size(coins)][amount] == 1000000 ? -1 : dp[size(coins)][amount];
    }
};