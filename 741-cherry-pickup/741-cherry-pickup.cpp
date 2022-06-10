class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = size(grid) , m = size(grid[0]);
        
        int dp[n][n][n][n];
        memset(dp,-1,sizeof dp);
        
        vector<vector<int>> dir = {
            {1,0} , {0,1}
        };
        
        auto isVal = [&](int i,int j){
            return i>=0 and j>=0 and i<n and j<m and grid[i][j] != -1;    
        };
        
        function<int(int,int,int,int)> pick = [&](int i1,int j1,int i2,int j2){
            if(!isVal(i1,j1) or !isVal(i2,j2))
                return (int)-1e8;
            
            if(dp[i1][j1][i2][j2] != -1)
                return dp[i1][j1][i2][j2];
            
            if(i1 == n-1 and j1 == n-1)
                return  grid[i1][j1];
            
            if(i2 == n-1 and j2 == n-1)
                return grid[i2][j2];
            
            int cherry=0;
            if(i1 == i2 and j1 == j2)
                cherry = grid[i1][j1];
            else
                cherry = grid[i1][j1] + grid[i2][j2];
            
            int maxi = -1e8;
            for(auto &d1 : dir)
            {
                for(auto &d2 : dir)
                {
                    maxi = max(maxi,pick(i1 + d1[0] , j1 + d1[1] , i2 + d2[0], j2 + d2[1]));
                }
            }
            
            
            return dp[i1][j1][i2][j2] = cherry + maxi;
        };
        
        return max(0,pick(0,0,0,0));
    }
};


// 1 1 -1
// 1 -1 1
// -1 1 1