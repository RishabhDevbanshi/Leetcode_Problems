class Solution {
    vector<pair<int,int>> direction = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 0) continue;
                for(auto &p : direction)
                {
                    int x = i + p.first , y = j + p.second;
                    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y] == 0)
                        perimeter++;
                }
            }
        }
        
        return perimeter;
    }
};