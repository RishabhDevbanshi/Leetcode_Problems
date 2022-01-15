// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    void dfs(vector<int> g[],int par,int node,set<vector<int>> &st,int disc[],int low[],int timer)
    {
        disc[node] = low[node] = timer++;
        
        for(auto &child : g[node])
        {
            if(disc[child] == -1)
            {
                dfs(g,node,child,st,disc,low,timer);
                low[node] = min(low[node],low[child]);
                if(low[child] > disc[node])
                    st.insert({node,child});
            }
            else if(child != par) low[node] = min(low[node],disc[child]);
        }
        
        
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int timer = 0;
        int disc[V] , low[V];
        memset(disc,-1,sizeof disc);
        memset(low,-1,sizeof low);
        
        set<vector<int>> st;
        
        for(int i=0;i<V;i++)
        {
            if(disc[i] == -1)
                dfs(adj,-1,i,st,disc,low,timer);
        }
        
        return st.find({c,d}) != st.end() || st.find({d,c}) != st.end();
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
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends