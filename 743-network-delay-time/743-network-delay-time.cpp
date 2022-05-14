class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> g[n+1];
        
        for(auto &v : times)
        {
            g[v[0]].push_back({v[1],v[2]});
        }
        
        vector<int> dist(n+1,1e9);
        typedef pair<int,int> pii;
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        pq.push({dist[k] = 0,k});
        
        while(!pq.empty())
        {
            auto [d,node] = pq.top();
            pq.pop();
            
            for(auto [child,wt] : g[node])
            {
                if(dist[child] > d + wt)
                    pq.push({dist[child] = d + wt,child});
            }
        }
        
        int res = 0;
        
        for(int i=1;i<=n;i++)
        {
            if(dist[i] == 1e9)
                return -1;
            res = max(res,dist[i]);
        }
        
    
        return res;    
    }
};