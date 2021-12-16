class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n<2)
        {
            vector<int> res;
            for(int i=0;i<n;i++) res.push_back(i);
            return res;
        }
        
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        
        for(int i=0;i<size(edges);i++)
        {
            int u = edges[i][0] , v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            in[u]++ , in[v]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(in[i] == 1) q.push(i);
        }
        
        vector<int> res;
        
        while(!q.empty())
        {
            int sz = size(q);
            res.clear();
            
            for(int i=0;i<sz;i++)
            {
                int node = q.front(); q.pop();
                res.push_back(node);
                
                for(auto &child : adj[node])
                {
                    in[child]--;
                    if(in[child] == 1)
                    {
                        q.push(child);
                    }
                }
            }
        }
        
        
        return res;
        
        
        
    }
};