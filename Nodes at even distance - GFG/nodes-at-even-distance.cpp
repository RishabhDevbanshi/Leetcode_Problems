// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int countOfNodes(vector<int> graph[], int n)
    {
        bool vis[n+1];
        memset(vis,false,sizeof vis);
        
        int cnt = 0;
        
        function<void(int,int)> dfs = [&](int node,int dist){
                vis[node] = true;
                cnt += !(dist&1);
                
                for(auto &child : graph[node])
                {
                    if(vis[child])
                        continue;
                    dfs(child,dist+1);
                }
        };
        
        dfs(1,0);
        
        int even = (cnt * (cnt-1))>>1;
        int o_n = n - cnt;
        int odd = (o_n * (o_n-1))>>1;
        
        return even + odd;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends