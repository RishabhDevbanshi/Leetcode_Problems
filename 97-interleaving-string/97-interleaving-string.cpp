class Solution {
    
    int dp[105][105][205];
    
    bool recur(string &a,string &b,string &c,int i,int j,int k)
    {
        if(k == size(c))
            return true;
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        if(i<size(a) and j<size(b))
        {
            bool ok = false;
            ok = a[i] == c[k] ? recur(a,b,c,i+1,j,k+1) : false;
            if(ok) return dp[i][j][k] = true;
            ok = b[j] == c[k] ? recur(a,b,c,i,j+1,k+1) : false;
            
            return dp[i][j][k] = ok;
        }
        else if(i<size(a))
        {
            bool ok = false;
            ok = a[i] == c[k] ? recur(a,b,c,i+1,j,k+1) : false;
            return dp[i][j][k] = ok;
        }
        else if(j < size(b))
        {
            bool ok = false;
            ok = b[j] == c[k] ? recur(a,b,c,i,j+1,k+1) : false;
            return dp[i][j][k] = ok;
        }
        
        return dp[i][j][k] = false;
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(size(s3) != size(s1) + size(s2))
            return false;
        memset(dp,-1,sizeof dp);
        return recur(s1,s2,s3,0,0,0);
    }
};