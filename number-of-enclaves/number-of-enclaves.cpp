int drow[4] = {0,1,0,-1};
int dcol[4] = {1,0,-1,0};

class Solution {
    bool isValid(vector<vector<int>> &grid,int i,int j,int r,int c)
    {
        if(i>=0 and j>=0 and i<r and j<c and grid[i][j] == 1) return true;
        
        return false;
    }
    
    void dfs(vector<vector<int>> &grid,int i,int j,int r,int c)
    {
        if(!isValid(grid,i,j,r,c)) return;
        
        grid[i][j] = -1;
        
        for(int x = 0;x<4;x++)
        {
            dfs(grid,i+drow[x],j+dcol[x],r,c);
        }
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size() , c = grid[0].size();
        
        for(int i=0;i<r;i++)
        {
            dfs(grid,i,0,r,c);
            dfs(grid,i,c-1,r,c);
        }
        
        for(int i=0;i<c;i++)
        {
            dfs(grid,0,i,r,c);
            dfs(grid,r-1,i,r,c);
        }
        
        int cnt = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++) if(grid[i][j] == 1) cnt++;
        }
        
        return cnt;
    }
};





