class Solution {
    vector<vector<int>> dir = {
        {1,0} , {0,1} , {-1,0} , {0,-1}
    };
    
    bool isValid(int *mx,int *my,vector<vector<int>> &grid)
    {
        int x = *mx , y = *my;
        return x>=0 and y>=0 and x<size(grid) and y<size(grid[0]);
    }
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        // map<pair<int,int>,bool> vis;
        bool vis[size(grid)][size(grid[0])];
        memset(vis,false,sizeof vis);
        
        // unordemap<int,vector<vector<int>>> res;
        
        int l = pricing[0] , u = pricing[1];
        
        queue<pair<int, int>> q{{{start[0], start[1]}}};
        // queue<pair<int,int>> q;
        // q.emplace({start[0],start[1]});
        vis[start[0]][start[1]] = true;
        
        int cnt = 0;
        int rank = 0;
        
        vector<vector<int>> ans;
        
        while(!q.empty())
        {
            rank++;
            int sz = size(q);
            vector<vector<int>> arr;
            for(int i=0;i<sz;i++)
            {
                auto cor = q.front();
                q.pop();
                auto &[x,y] = cor;
                if(grid[x][y] > 1 and grid[x][y]>=l and grid[x][y]<=u) arr.push_back({x,y});
                
                for(auto &d : dir)
                {
                    int nx = x + d[0] , ny = y + d[1];
                    if(isValid(&nx,&ny,grid) and grid[nx][ny] != 0 and !vis[nx][ny])
                    {
                        // vis[{nx,ny}] = true;
                        vis[nx][ny] = true;
                        q.emplace(nx,ny);   
                    }
                }
            }
            
            sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
                int ax = a[0] , ay = a[1], bx = b[0] , by = b[1];
                if(grid[ax][ay] == grid[bx][by]) {
                    if(ax == bx) return ay < by;
                    else return ax < bx;
                }
                else return grid[ax][ay] < grid[bx][by];
            });
            
            for(auto &val : arr)
            {
                ans.push_back(val);
                if(size(ans) == k)
                    return ans;
            }
            
            // res[rank] = arr;
        }
        
        
        
//         for(auto &[key,value] : res)
//         {
//             for(auto &val : value) 
//             {
//                 ans.push_back(val);
//                 if(size(ans) == k)
//                     return ans;
//             }
//         }
        
        return ans;
    }
};