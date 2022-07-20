class Solution {
public:
    int minInsertions(string &str) {
        string rev = str;
        reverse(rev.begin(),rev.end());
        
        int n = str.size();
        
        
        vector<int> prev(n+1);
        
        for(int i=1;i<=n;i++)
        {
            vector<int> dp(n+1);
            for(int j=1;j<=n;j++)
            {
                if(str[i-1] == rev[j-1])
                    dp[j] = 1 + prev[j-1];
                else
                    dp[j] = max(prev[j],dp[j-1]);
            }
            prev = dp;
        }
        
        
        return n - prev[n];
    }
};