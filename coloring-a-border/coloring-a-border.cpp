//directions
int dr[4] = {1,0,0,-1};
int dc[4] = {0,1,-1,0};

class Solution {
    bool isValid(int i,int j,int r,int c)
    {
        if(i<0 or j<0 or i>=r or j>=c)
            return false;
        return true;
    }
    
    void dfs(vector<vector<int>> &grid,int r,int c,int i,int j,int col)
    {
        if(!isValid(i,j,r,c) or grid[i][j] != col) 
            return;
        
        grid[i][j] = -1;
        for(int x=0;x<4;x++)
            dfs(grid,r,c,i+dr[x],j+dc[x],col);
    }
    
    bool surrounded(vector<vector<int>> &grid,int i,int j,int r,int c)
    {   
        if(i>0 and j>0 and i<r-1 and j<c-1)
        {
            if(grid[i-1][j] == -1 and grid[i+1][j] == -1
              and grid[i][j-1] == -1 and grid[i][j+1] == -1) 
                return true; 
            
            else return false;
        }
        
        return false;
    }
    
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int col = grid[r0][c0];
        
        int r = grid.size() , c = grid[0].size();
        
        dfs(grid,r,c,r0,c0,col);
        
        map<pair<int,int>,int> mp;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == -1 and surrounded(grid,i,j,r,c))
                {
                   mp[{i,j}] = 1;
                }
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == -1)
                {
                    if(mp.find({i,j}) != mp.end()) grid[i][j] = col;
                   else grid[i][j] = color;
                }
            }
        }
        
        return grid;
    }
};