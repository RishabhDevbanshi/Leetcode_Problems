#define pii pair<int,int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<pii> arr[n+1];
        
        for(int i=0;i<m;i++)
        {
            int u = times[i][0] , v = times[i][1], wt = times[i][2];
            arr[u].push_back({v,wt});
        }
        
        vector<bool> vis(n+1,false);
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        
        priority_queue<pii,vector<pii>,greater<pii>> pq; // {distance,vertex}
        pq.push({dist[k],k});
        
        while(!pq.empty())
        {
            int v = pq.top().second;
            pq.pop();
            
            if(vis[v]) continue;
            vis[v] = true;
            
            for(auto p : arr[v])
            {
                int u = p.first , wt = p.second;
                if(dist[u] > dist[v]+wt)
                {
                    dist[u] = dist[v]+wt;
                    pq.push({dist[u],u});
                }
            }
        }
        
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        
        return ans;
    }
};