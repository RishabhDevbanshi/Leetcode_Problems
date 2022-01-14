class Solution {
    
    bool dfs(vector<int> g[],int node,int col,int vis[])
    {
        vis[node] = col;
        for(auto &child : g[node])
        {
            if(vis[child] == -1)
            {
                dfs(g,child,1-col,vis);
            }
            else if(vis[child] == vis[node]) return false;
        }
        
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> g[n+1];
        
        for(int i=0;i<size(dislikes);i++)
        {
            int u = dislikes[i][0] , v = dislikes[i][1];
            g[v].push_back(u);
            g[u].push_back(v);
        }
        
        int vis[n+1];
        memset(vis,-1,sizeof vis);
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i] == -1)
            {
                bool ok = dfs(g,i,0,vis);
                if(!ok) return false;
            }
        }
        
        // return false;
        
        return true;
    }
};