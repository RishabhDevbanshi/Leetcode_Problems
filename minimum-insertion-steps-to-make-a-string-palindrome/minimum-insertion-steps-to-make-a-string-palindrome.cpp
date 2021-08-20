class Solution {
    int lcs(string a,string b)
    {
        int dp[a.size()+1][b.size()+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=a.size();i++)
        {
            for(int j=1;j<=b.size();j++)
            {
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        return dp[a.size()][b.size()];
    }
public:
    int minInsertions(string str) {
        string rev = str;
        reverse(rev.begin(),rev.end());
        
        int lps = lcs(str,rev);
        // cout<<lps<<"\n";
        
        return str.size() - lps;
    }
};