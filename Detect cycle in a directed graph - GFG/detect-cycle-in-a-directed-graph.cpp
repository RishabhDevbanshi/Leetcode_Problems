// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    bool dfs(vector<int> adj[],int src,vector<bool> &vis,vector<bool> &dvis)
    {
        vis[src] = dvis[src] = true;
        
        for(auto &child : adj[src])
        {
            if(!vis[child])
            {
                bool hasCycle = dfs(adj,child,vis,dvis);
                if(hasCycle) return true;
            }
            else if(dvis[child]) return true;
        }
        
        dvis[src] = false;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false) , dvis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                bool hasCycle = dfs(adj,i,vis,dvis);
                if(hasCycle) return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends