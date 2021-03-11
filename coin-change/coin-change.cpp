class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int *dp = new int[amount + 1];
        for(int i=0;i<=amount;i++) dp[i] = amount+1;
        dp[0] = 0;
        
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(coins[j] <= i)
                {
                    dp[i] = min(dp[i],dp[ i - coins[j] ] + 1);
                }
            }
        }
        
        int ans = dp[amount] > amount ? -1 : dp[amount];
        
        delete[] dp;
        return ans;
    }
};