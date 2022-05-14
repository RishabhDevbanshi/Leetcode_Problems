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
    int coinChange(vector<int>& arr, int amt) {
        int n = arr.size();
        // vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        
        int dp[n+1][amt+1];

        for(int i=1;i<=amt;i++) dp[0][i] = (int)1e5;
        for(int i=0;i<=n;i++) dp[i][0] = 0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amt;j++)
            {
                if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(dp[i-1][j],1 + dp[i][j - arr[i-1]]);
            }
        }
        
        int val = dp[n][amt];
        
        return val == (int)1e5 ? -1 : val;
    }
};