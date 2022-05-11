class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5,1);
        
        for(int i=1;i<n;i++)
        {
            vector<int> tmp(5);
            tmp[0] = dp[0];
            tmp[1] = tmp[0] + dp[1];
            tmp[2] = tmp[1] + dp[2];
            tmp[3] = tmp[2] + dp[3];
            tmp[4] = tmp[3] + dp[4];
            
            dp = tmp;
        }
        
        int tot = 0;
        for(auto &val : dp)
            tot += val;
        
        return tot;
    }
};