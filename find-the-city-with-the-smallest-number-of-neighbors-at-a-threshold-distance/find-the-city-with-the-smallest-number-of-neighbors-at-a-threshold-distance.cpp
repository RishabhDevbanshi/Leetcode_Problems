#define pii pair<int,int>
class Solution {
    int dijikstra(int n,vector<pii> arr[],int start,int th)
    {
        vector<bool> vis(n,false);
        vector<int> dist(n,INT_MAX);
        dist[start] = 0;
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({dist[start],start});
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            
            if(vis[u]) continue;
            vis[u] = true;
            
            for(auto p : arr[u])
            {
                int v = p.first , wt = p.second;
                // cout<<v<<"\n";
                if(dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v],v});
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            // cout<<dist[i]<<" ";
            if(i == start) continue;
            if(dist[i] <= th) cnt++;
        }
        // cout<<"\n";
        return cnt;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pii> arr[n];
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0] , v = edges[i][1], wt = edges[i][2];
            arr[u].push_back({v,wt});
            arr[v].push_back({u,wt});
        }
        
        int toret = -1,mn = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int ans = dijikstra(n,arr,i,distanceThreshold);
            if(mn >= ans)
            {
                mn = ans;
                toret = i;
            }
        }
        
        return toret;
    }
};







