class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>> g[n];
        for(auto &val : edges)
        {
            g[val[0]].push_back({val[1],val[2]});
            g[val[1]].push_back({val[0],val[2]});
        }
        
        auto dijikstra = [&](int root){
            vector<int> dist(n,INT_MAX);
            typedef pair<int,int> pii;
            priority_queue<pii,vector<pii>,greater<pii>> pq;
                        
            pq.push({dist[root] = 0,root});
            
            while(!pq.empty())
            {
                auto [d,node] = pq.top();
                pq.pop();
                
                for(auto &[child,wt] : g[node])
                {
                    if(d + wt < dist[child])
                        pq.push({dist[child] = d + wt,child});
                }
            }
            
            int cnt = 0;
            
            for(int i=0;i<n;i++)
            {
                if(i != root and dist[i] <= distanceThreshold)
                    cnt++;
            }
            
            return cnt;
        };
        
        int city=0,maxi=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int cnt = dijikstra(i);
            // cout << cnt << "\n";
            if(maxi >= cnt)
                maxi = cnt , city = i;
        }
                
        return city;
    }
};