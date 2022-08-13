class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        auto dead_end = [&](string &str,int i){
          int tot=0;
            for(int x=i;x<size(str);x++) 
                tot += int(str[x]);
            return tot;
        };
        
        vector<vector<int>> dp(size(s1)+1,vector<int>(size(s2)+1));
        
        for(int i=1;i<=size(s2);i++)
            dp[0][i] = dp[0][i-1] + s2[i-1];
        
        for(int i=1;i<=size(s1);i++)
            dp[i][0] = dp[i-1][0] + s1[i-1];
        
        for(int i=1;i<=size(s1);i++)
        {
            for(int j=1;j<=size(s2);j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(int(s1[i-1]) + dp[i-1][j] , int(s2[j-1]) + dp[i][j-1]);
            }
        }
        
        
        return dp.back().back();
        
    }
};