// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    
	    function<bool(int,int)> dfs = [&](int node,int col){
	       // cout << col << "\n";
	       color[node] = col;
	       for(auto &child : adj[node])
	       {
	           if(color[child] == -1)
	           {
	             bool ok = dfs(child,1-col);
	             if(!ok)
	                return false;
	           }
	           else if(color[child] == col)
	                return false;
	       }
	       
	       return true;
	    };
	    
	   // cout << V << "\n";
	    
	    for(int i=0;i<V;i++)
	    {
	       // cout << color[i] << "\n";
	        if(color[i] == -1)
	        {
	           // cout << "jere \n";
	            bool ok = dfs(i,0);
	            if(!ok)
	                return false;
	        }
	    }
	    
	   // for(int i=0;i<V;i++)
	   //     cout << color[i] << " ";
	    
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends