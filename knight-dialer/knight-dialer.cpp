class Solution {
    
    const int mod = (int)1e9 + 7;
    
    vector<vector<int>> dir = {
        {2,1} , {2,-1} , {-2,1} , {-2,-1},
        {1,2} , {-1,2} , {1,-2} , {-1,-2}
    };
    
    bool isValid(int i,int j,int n)
    {
        return (i>=0 and j>=0 and i<4 and j<3);
    }
    
    int dp[4][3][5002];
    
    int recur(int i,int j,int n)
    {
        if(!isValid(i,j,n) || (i == 3 and (j == 0 || j == 2)))
            return 0;
        if(n == 1) return 1;
        
        if(dp[i][j][n] != -1)
            return dp[i][j][n];
        
        int ways = 0;
        
        for(auto &ele : dir)
        {
            ways = (ways%mod + recur(i+ele[0],j+ele[1],n-1)%mod)%mod;
        }
        
        return dp[i][j][n] = ways%mod;
    }
    
    
public:
    int knightDialer(int n) {
        
        memset(dp,-1,sizeof(dp));
        
        int ways = 0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                ways = (ways%mod + recur(i,j,n)%mod)%mod;
            }
        }
        
        return ways%mod;
    }
};