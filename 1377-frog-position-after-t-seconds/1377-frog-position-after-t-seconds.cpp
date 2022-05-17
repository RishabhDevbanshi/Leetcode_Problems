class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        
        // if(target<=t)return 0;
        vector<int> adj[n+1];
        vector<double> prob(n+1,0);
        vector<int> vis(n+1);
        for(auto i:edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        prob[1] = 1.00;
        while(!q.empty() && t--) { 
            int sz = size(q);
            for(int i=0;i<sz;i++) {
                int node = q.front(); q.pop();
                int cnt = 0;
                for(int child:adj[node]) if(!vis[child]) cnt++; 
                for(int child:adj[node]) {
                    if(!vis[child]) {
                        q.push(child);
                        prob[child] = prob[node]*1.0/cnt;
                        vis[child] = 1;
                    }
                } 
                if(cnt) prob[node] = 0;
            }
        }
        return prob[target];
        
        
    }
};