class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] != 0 or grid.back().back() != 0)
            return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int len = 1;
        
        vector<pair<int,int>> dir = {
            {1,0} , {-1,0} , {0,1} , {0,-1} , {1,1} , {-1,-1} , {1,-1} , {-1,1}
        };
        
        auto isVal = [&](int i,int j){
            return i>=0 and j>=0 and i<size(grid) and j<size(grid[0]) and grid[i][j] == 0;
        };
        
        while(!q.empty())
        {
            int sz = size(q);
            for(int i=0;i<sz;i++)
            {
                auto [x,y] = q.front();
                q.pop();
                
                if(x == size(grid)-1 and y == size(grid[0])-1)
                    return len;
                
                
                grid[x][y] = 2;
                
                for(auto &[a,b] : dir)
                {
                    if(isVal(x+a,y+b))
                        q.push({x+a,y+b}) , grid[x+a][y+b] = 2;
                }
                
            }
            
            len++;
        }
        
        return -1;
    }
};