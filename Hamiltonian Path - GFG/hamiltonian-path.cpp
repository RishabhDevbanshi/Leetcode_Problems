// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    bool dfs(vector<int> g[],int N,int node,bool vis[],int cnt)
    {
        vis[node] = true;
        cnt++;
        if(cnt == N) return true;
        
        for(auto &child : g[node])
        {
            if(!vis[child])
            {
                bool ok = dfs(g,N,child,vis,cnt);
                if(ok) return true;
            }
        }
        
        vis[node] = false;
        
        return false;
        
    }
    
    
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int> g[N+1];
        for(int i=0;i<M;i++)
        {
            int u = Edges[i][0] , v = Edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        for(int i=1;i<=N;i++)
        {
            bool vis[N+1];
            memset(vis,false,sizeof vis);
            bool ok = dfs(g,N,i,vis,0);
            if(ok) return true;
        }
        
        
        return false;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends