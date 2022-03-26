// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    bool recur(vector<int> adj[],int node,int par,bool vis[])
    {
        vis[node] = true;
        for(auto &child : adj[node])
        {
            if(!vis[child])
            {
                bool ok = recur(adj,child,node,vis);
                if(ok) return ok;
            }
            else if(child != par)
                return true;
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V];
        memset(vis,false,sizeof vis);
        
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                bool ok = recur(adj,i,-1,vis);
                if(ok)
                    return true;
            }
        }
        
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends