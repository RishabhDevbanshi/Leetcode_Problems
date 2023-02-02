class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> dp(n),sz(n),ans(n);
        
        vector<int> g[n];
        for(auto &edge : edges)
        {
            g[edge[0]].push_back(edge[1]); 
            g[edge[1]].push_back(edge[0]);
        }
        
        function<void(int,int)> dfs = [&](int node,int prev){
            dp[node] = 0;
            sz[node] = 1;
            
            for(auto &child : g[node])
            {
                if(child == prev)
                    continue;
                dfs(child,node);
                sz[node] += sz[child];
                dp[node] += dp[child] + sz[child];
            }
        };
        
        function<void(int,int)> reroot = [&](int node,int src){
            dp[src] -= dp[node] + sz[node];
            sz[src] -= sz[node];
            
            dp[node] += dp[src] + sz[src];
            sz[node] += sz[src];
        };
        
        function<void(int,int)> dfs1 = [&](int node,int prev){
            ans[node] = dp[node];
            for(auto &child : g[node])
            {
                if(child == prev)
                    continue;
                reroot(child,node);
                dfs1(child,node);
                reroot(node,child);
            }
        };
        
        dfs(0,-1);
        dfs1(0,-1);
        
        return ans;
    }
};