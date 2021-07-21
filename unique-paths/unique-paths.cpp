class Solution {
    bool isValid(int n,int m,int r,int c)
    {
        if(r<0 or c<0 or r>=n or c>=m) return false;
        return true;
    }
    
    int dfs(int n,int m,int r,int c,vector<vector<int>> &dp)
    {
        if(!isValid(n,m,r,c)) return dp[r][c] = 0;
        
        if(r == n-1 and c == m-1) 
            return dp[r][c] = 1;
        
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int right = dfs(n,m,r,c+1,dp);
        int down = dfs(n,m,r+1,c,dp);
        
        return dp[r][c] = right + down;
    }
    
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(105,vector<int>(105,-1));
        return dfs(n,m,0,0,dp);
    }
};