class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        bool dp[n][n];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++) dp[i][i] = true;
        
        string res = "";
        res += s.front();
        
        // int x=0,y=0,len=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = j-i==1 || dp[i+1][j-1]; 
                }
                
                if(dp[i][j]==1 and res.size() < j - i + 1)
                {
                    res = s.substr(i,j-i+1);
                }
            }
        }
        
        return res;
    }
};