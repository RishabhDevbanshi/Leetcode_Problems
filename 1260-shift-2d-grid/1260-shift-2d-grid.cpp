class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n = size(grid) , m = size(grid[0]);
        
        function<void()> rotate = [&]()->void{
            int last = grid.back().back();
            
            for(int i=n-2;i>=0;i--)
            {
                grid[i+1][m-1] = grid[i][m-1];
            }
            
            grid[0][m-1] = last;
            
            vector<int> tmp;
            
            for(int i=0;i<n;i++)
                tmp.push_back(grid[i][m-1]);
            
            for(int i=m-2;i>=0;i--)
            {
                for(int j=0;j<n;j++)
                {
                    grid[j][i+1] = grid[j][i];
                }
            }
            
            int idx = 0;
            
            for(int i=0;i<n;i++)
                grid[i][0] = tmp[idx++];
        };
        
        while(k--)
            rotate();
        
        return grid;
    }
};