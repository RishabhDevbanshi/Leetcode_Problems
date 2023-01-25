class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        
        int n = size(edges);
        vector<vector<int>> g(n);
        
        for(int i=0;i<n;i++)
        {
            if(edges[i] != -1)
                g[i].push_back(edges[i]);
        }
        
        auto bfs = [&](int node){
            queue<int> q;
            q.push(node);
            
            vector<long> dist(n+1,1e12);
            int level = 0;
            
            vector<bool> vis(n+1,false);
            
            while(!q.empty())
            {
                int sz = size(q);
                for(int i=0;i<sz;i++)
                {
                    int fr = q.front(); q.pop();
                    dist[fr] = level;
                    vis[fr] = true;
                    for(auto &child : g[fr])
                    {
                        if(!vis[child])
                            q.push(child) , vis[child] = true;
                    }
                }
                level++;
            }
            
            return dist;
        };
        
        auto a = bfs(node1) , b = bfs(node2);
        
        long maxi = 1e12 , node = -1;
        
        for(int i=0;i<n;i++)
        {
            if(a[i] != 1e12 and b[i] != 1e12)
            {
               int mx = max(a[i],b[i]);
               if(mx < maxi)
                   maxi = mx , node = i;
            }
        }
        
        return node;
    }
};