class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> g[n+1];
        for(auto &dis : dislikes)
        {
            g[dis[0]].push_back(dis[1]);
            g[dis[1]].push_back(dis[0]);
        }
        
        vector<int> vis(n+1,-1);
        
        function<bool(int,int)> dfs = [&](int node,int col){
            vis[node] = col;
            for(auto &child : g[node])
            {
                if(vis[child] == -1)
                    dfs(child,1-col);
                else if(vis[child] == vis[node])
                    return false;
            }
            return true;
        };
        
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i] == -1)
            {
                bool ok = dfs(i,0);
                if(!ok)
                    return false;
            }
        }
        
        return true;
    }
};