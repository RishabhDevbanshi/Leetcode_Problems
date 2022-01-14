// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        bool vis[V];
        int par[V] , dist[V];
        memset(vis,false,sizeof vis);
        memset(par,-1,sizeof par);
        memset(dist,1e4,sizeof dist);
        
        dist[0] = 0;
        
        typedef pair<int,int> pii;
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({dist[0],0});
        
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            
            int node = p.second;
            vis[node] = true;
            
            for(auto &child_pair : adj[node])
            {
                int child = child_pair[0] , wt = child_pair[1];
                
                // cout<<child<<" "<<wt<<"\n";
                // cout<<dist[child]<<" "<<wt<<"\n";
                if(!vis[child] and dist[child] > wt)
                {
                    par[child] = node;
                    pq.push({dist[child]=wt,child});
                }
            }
        }
        
        int sum = 0;
        for(int i=0;i<V;i++)  sum += dist[i];
        
        return sum;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends