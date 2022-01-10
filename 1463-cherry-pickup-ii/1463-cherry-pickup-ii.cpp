class Solution {
    
    vector<int> direc = {-1,0,1};
    int dp[71][71][71];
    
    
    bool isValid(vector<vector<int>> &grid,int i,int j)
    {
        return i>=0 and j>=0 and i<size(grid) and j<size(grid[0]);
    }
    
    int dfs(vector<vector<int>> &grid,int i,int j,int y)
    {
        if(!isValid(grid,i,j) || !isValid(grid,i,y)) return 0;
        
        if(dp[i][j][y] != -1)
            return dp[i][j][y];
        
        int res = 0;
        
        for(auto &d : direc)
        {
            for(auto &r : direc)
            {
                res = max(res,dfs(grid,i+1,j+d,y+r));
            }
        }
        
        
        res += j == y ? grid[i][j] : grid[i][j] + grid[i][y];
        
        
        return dp[i][j][y] = res;
        
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
        
        return dfs(grid,0,0,size(grid[0])-1);
    }
};