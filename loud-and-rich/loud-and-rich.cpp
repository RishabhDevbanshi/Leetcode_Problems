class Solution {
    void dfs(vector<int> adj[],int src,vector<int> &vis,int *mn,int *res,vector<int> &quiet)
    {
        vis[src] = true;
        if(*mn > quiet[src])
        {
            *mn = quiet[src] , *res = src;
        }
        for(auto node : adj[src])
        {
            if(!vis[node]) 
                dfs(adj,node,vis,mn,res,quiet);
        }
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[n];
        for(auto v : richer)
        {
            adj[v.back()].push_back(v.front());
        }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            int mn = INT_MAX,res;
            vector<int> vis(n,false);
            dfs(adj,i,vis,&mn,&res,quiet);
            ans.push_back(res);
        }
        
        return ans;
    }
};