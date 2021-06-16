int drow[4] = {0,1,-1,0};
int dcol[4] = {1,0,0,-1};

class Solution {
    bool isValid(int i,int j,int r,int c)
    {
        if(i>=0 and j>=0 and i<r and j<c) return true;
        
        return false;
    }
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int r = mat.size() , c = mat[0].size();
        vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            for(int x = 0; x < 4; x++)
            {
                int a = node.first + drow[x] , b = node.second + dcol[x];
                if(!isValid(a,b,r,c)) continue;
                
                if(dist[a][b] > dist[node.first][node.second] + 1)
                {
                    dist[a][b] = dist[node.first][node.second] + 1;
                    q.push({a,b});
                }
            }
        }
        
        return dist;
    }
};