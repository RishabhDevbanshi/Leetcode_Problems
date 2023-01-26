class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> g[n];
        for(auto &flight : flights)
            g[flight[0]].push_back({flight[1],flight[2]});
        
        typedef array<int,3> vi;
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        pq.push({0,src,0});
        
        vector<int> steps(n,INT_MAX);
        // dist[src]=;
        
        while(!pq.empty())
        {
            auto fr = pq.top();
            pq.pop();
            
            int cost=fr[0] , node=fr[1], stops=fr[2];
            if(steps[node] < stops || stops > k+1)
                continue;
            steps[node] = stops;
            if(node == dst)
                return cost;
            // if(dist[node] < cost)
                // continue;
            
            for(auto &[child,wt] : g[node])
            {
                    pq.push({cost+wt,child,stops+1});
            }
        }
        
        return -1;
    }
};