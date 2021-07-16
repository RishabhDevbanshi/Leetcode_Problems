class Solution {
    int recur(vector<int> &coins,int tar,int n,vector<vector<int>> &dp)
    {
        if(tar == 0) return dp[n][tar] = 0;
        if(n == 0) return dp[n][tar] = INT_MAX - 3;
        
        if(dp[n][tar] != -1)
                return dp[n][tar];
        
        if(coins[n-1] > tar)
            return dp[n][tar] = recur(coins,tar,n-1,dp);
        
        return dp[n][tar] = min(recur(coins,tar,n-1,dp),1 + recur(coins,tar-coins[n-1],n,dp));
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int val = recur(coins,amount,coins.size(),dp);

        return val == INT_MAX-3 ? -1 : val;
    }
};