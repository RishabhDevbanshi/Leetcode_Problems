class Solution {
    vector<vector<int>> ans;
    
    void dfs(vector<int> adj[],int node,int par,int timer,vector<int> &low,vector<int> &tim,
             vector<int> &vis)
    {
        if(vis[node]) return;
        
        vis[node] = 1;
        low[node] = tim[node] = timer++;
        
        for(int ele : adj[node])
        {
            if(ele == par) continue;
            
            if(!vis[ele])
            {
                dfs(adj,ele,node,timer,low,tim,vis);
                low[node] = min(low[node],low[ele]);
                
                if(low[ele] > tim[node]) ans.push_back({ele,node});
            }
            else low[node] = min(low[node],tim[ele]);
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<int> adj[n];
        ans.clear();
        
        for(int i=0;i<con.size();i++)
        {
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }
        
        int timer = 0;
        vector<int> low(n,-1),tim(n,-1),vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) dfs(adj,i,-1,timer,low,tim,vis);
        }
        
        return ans;
    }
};