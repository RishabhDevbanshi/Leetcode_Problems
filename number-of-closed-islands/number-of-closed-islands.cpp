class Solution {
    bool terminal;
    
    void dfs(vector<vector<int>> &grid,int i,int j,int r,int c)
    {
        if(i<0 or j<0 or i>=r or j>=c)
        {
            terminal = true;
            return;
        }
        
        if(grid[i][j] == 1) return;
        
        grid[i][j] = 1;
        
        dfs(grid,i+1,j,r,c); dfs(grid,i-1,j,r,c);
        dfs(grid,i,j+1,r,c); dfs(grid,i,j-1,r,c);
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size() , c = grid[0].size();
        
        // bool terminal;
        int cnt = 0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == 0)
                {
                    terminal = false;
                    dfs(grid,i,j,r,c);
                    
                    if(!terminal) cnt++;
                }
            }
        }
        
        return cnt;
    }
};