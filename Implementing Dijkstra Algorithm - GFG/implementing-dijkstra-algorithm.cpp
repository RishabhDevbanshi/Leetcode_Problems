// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;
        
        typedef pair<int,int> pii;
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({dist[S],S});
        
        while(!pq.empty())
        {
            auto p = pq.top(); pq.pop();
            int d = p.first , node = p.second;
            
            for(auto &child : adj[node])
            {
                // cout<<child[0]<<" "<<child[1]<<"\n";
                if(dist[child[0]] == INT_MAX || dist[child[0]] > d + child[1])
                {
                    dist[child[0]] = d + child[1];
                    pq.push({dist[child[0]],child[0]});
                }
            }
            
        }
        
        
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends