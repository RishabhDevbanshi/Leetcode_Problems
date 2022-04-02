class Solution {
    
    void dfs(vector<vector<char>>  &grid,int i,int j)
    {
        if(i<0 || j<0 || i>=size(grid) || j>=size(grid[0]))
            return;
        
        if(grid[i][j] == '0' || grid[i][j] == '$')
        {
            grid[i][j] = '$';
            return;
        }
        
        grid[i][j] = '$';
        
        dfs(grid,i+1,j); // down
        dfs(grid,i-1,j); // up
        dfs(grid,i,j+1); // right
        dfs(grid,i,j-1); // left
    }
    
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int num_of_islands = 0;
        
        for(int i=0;i<size(grid);i++)
        {
            for(int j=0;j<size(grid[0]);j++)
            {
                if(grid[i][j] == '1')
                {
                    num_of_islands++;
                    dfs(grid,i,j);
                }
            }
        }
        
        return num_of_islands;
    }
};