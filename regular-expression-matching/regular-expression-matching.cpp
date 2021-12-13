class Solution {
    bool recur(string &s,string &p,int a,int b,vector<vector<int>> &dp)
    {
        if(b == size(p))
        {
            return a == size(s);
        }
        
        if(dp[a][b] != -1)
            return dp[a][b];
        
        if(p[b+1] == '*')
        {
            return recur(s,p,a,b+2,dp) ||
            (a<size(s) and (s[a] == p[b] || p[b] == '.') and recur(s,p,a+1,b,dp));
        }
        
        if(a<size(s) and (s[a] == p[b] || p[b] == '.'))
            return recur(s,p,a+1,b+1,dp);
        
        return false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(size(s)+1,vector<int>(size(p),-1));
        return recur(s,p,0,0,dp);
    }
};