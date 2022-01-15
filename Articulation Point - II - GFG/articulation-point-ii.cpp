// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void dfs(vector<int> g[],int par,int node,int disc[],int low[],int timer,bool mark[])
    {
        disc[node] = low[node] = timer++;
        int children = 0;
        for(auto &child : g[node])
        {
            // children++;
            if(disc[child] == -1)
            {
                children++;
                dfs(g,node,child,disc,low,timer,mark);
                low[node] = min(low[node],low[child]);
                if(par != -1 and low[child] >= disc[node])
                    mark[node] = true;
            }
            else if(child != par) low[node] = min(low[node],disc[child]);
        }
        
        if(par==-1 and children>1) mark[node] = true;
        
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int timer = 0;
        int disc[V] , low[V];
        memset(disc,-1,sizeof disc);
        memset(low,-1,sizeof low);
        
        bool mark[V];
        // bool vis[V];
        // memset(vis,false,sizeof vis);
        memset(mark,false,sizeof mark);
        
        for(int i=0;i<V;i++)
        {
            if(disc[i] == -1)
                dfs(adj,-1,i,disc,low,timer,mark);
        }
        vector<int> res;
        for(int i=0;i<V;i++) 
        {
            // cout<<mark[i]<<" ";
            if(mark[i]) res.push_back(i);
        }
        
        if(res.size() < 1) res.push_back(-1);
        
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends