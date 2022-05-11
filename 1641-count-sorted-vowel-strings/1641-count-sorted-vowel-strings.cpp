class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n][5];
        memset(dp,0,sizeof dp);
        for(int i=0;i<5;i++)
            dp[0][i] = 1;
        
        for(int i=1;i<n;i++)
        {
            dp[i][0] += dp[i-1][0];
            dp[i][1] += dp[i][0] + dp[i-1][1];
            dp[i][2] += dp[i][1] + dp[i-1][2];
            dp[i][3] += dp[i][2] + dp[i-1][3];
            dp[i][4] += dp[i][3] + dp[i-1][4];
        }
        
        int tot = 0;
        for(int i=0;i<5;i++)
            tot += dp[n-1][i];
        
        return tot;
    }
};