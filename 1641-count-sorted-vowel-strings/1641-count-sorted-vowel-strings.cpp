class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5,1);
        
        for(int i=1;i<n;i++)
        {
            dp[1] += dp[0];
            dp[2] += dp[1];
            dp[3] += dp[2];
            dp[4] += dp[3];
        }
        
        int tot = 0;
        for(auto &val : dp)
            tot += val;
        
        return tot;
    }
};