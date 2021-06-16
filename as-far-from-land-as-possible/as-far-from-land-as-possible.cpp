//4 directions
int drow[4] = {1,0,0,-1};
int dcol[4] = {0,1,-1,0};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        if(q.empty()) return -1;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            for(int x=0;x<4;x++)
            {
                int a = node.first + drow[x] , b = node.second + dcol[x];
                if(a<0 or b<0 or a>=n or b>=n) continue;
                if(dist[a][b] > dist[node.first][node.second] + 1)
                {
                    dist[a][b] = dist[node.first][node.second] + 1;
                    q.push({a,b});
                }
            }
            
        }
        
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                // cout<<dist[i][j]<<" ";
                if(dist[i][j] == 0 or dist[i][j] == INT_MAX) continue;
                ans = max(ans,dist[i][j]);
            }
            // cout<<"\n";
        }
        
        if(ans == INT_MIN) return -1;
        
        return ans;
    }
};