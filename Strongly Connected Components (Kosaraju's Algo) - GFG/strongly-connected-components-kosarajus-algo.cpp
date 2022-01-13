// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    void dfs(vector<int> adj[],int node,bool vis[],stack<int> &st)
    {
        vis[node] = true;
        for(auto &child : adj[node])
        {
            if(!vis[child])
                dfs(adj,child,vis,st);
        }
        st.push(node);
    }
    
    void findScc(vector<int> radj[],int node,vector<int> &comp,bool vis[])
    {
        vis[node] = true;
        comp.push_back(node);
        for(auto &ele : radj[node])
        {
            if(!vis[ele])
                findScc(radj,ele,comp,vis);
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        bool vis[V];
        memset(vis,false,sizeof vis);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                dfs(adj,i,vis,st);
        }
        // dfs(adj,0,vis,st);
        
        vector<int> radj[V];
        
        for(int i=0;i<V;i++)
        {
            for(auto &child : adj[i])
            {
                radj[child].push_back(i);
            }
        }
        
        memset(vis,false,sizeof vis);
        
        vector<vector<int>> scc;
        
        while(!st.empty())
        {
            int node = st.top(); st.pop();
            if(vis[node]) continue;
            vector<int> comp;
            // comp.push_back(node);
            findScc(radj,node,comp,vis);
            scc.push_back(comp);
        }
        
        return scc.size();
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends