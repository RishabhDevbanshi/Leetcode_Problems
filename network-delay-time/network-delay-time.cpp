#define pii pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<pii> arr[n+1];
        int ans = 0;
        
        for(int i=0;i<times.size();i++)
        {
            int u = times[i][0] , v = times[i][1] , w = times[i][2];
            // cout<<u<<" "<<v<<" "<<w<<"\n";
            arr[u].push_back({v,w});
        }
        
        vector<int> dist(n+1,INT_MAX);
        dist[src] = 0;
        
        vector<bool> vis(n+1,false);
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({dist[src],src});
        
        while(!pq.empty())
        {
            int prev_node = pq.top().second;
            pq.pop();
            
            if(vis[prev_node]) continue;
            
            vis[prev_node] = true;
            
            for(auto p : arr[prev_node])
            {
                int node = p.first , d = p.second;
                
                if(dist[prev_node] + d < dist[node])
                {
                    dist[node] = dist[prev_node] + d;
                    pq.push({dist[node],node});
                }
            }
        }
        
        for(int i=1;i<=n;i++) ans = max(ans,dist[i]);
        
        if(ans == INT_MAX) ans = -1;
        
        return ans;
    }
};