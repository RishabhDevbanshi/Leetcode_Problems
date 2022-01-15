class Solution {
    void dfs(vector<int> g[],int par,int node,int disc[],int low[],int timer,vector<vector<int>> &res)
    {
        disc[node] = low[node] = timer++;
        for(auto &child : g[node])
        {
            if(disc[child] == -1)
            {
                dfs(g,node,child,disc,low,timer,res);
                low[node] = min(low[node],low[child]);
                
                if(low[child] > disc[node])
                    res.push_back({node,child});
            }
            else if(child != par) low[node] = min(low[node],disc[child]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> g[n];
        
        for(auto &v : connections)
        {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        
        int disc[n] , low[n];
        memset(disc,-1,sizeof disc);
        memset(low,-1,sizeof low);
        
        vector<vector<int>> res;
        
        for(int i=0;i<n;i++)
        {
            if(disc[i] == -1)
                dfs(g,-1,i,disc,low,0,res);
        }
        
        return res;
    }
};