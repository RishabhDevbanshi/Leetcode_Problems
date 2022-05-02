// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int partyHouse(int N, vector<vector<int>> &g){
        // vector<vector<int>> g(adj.size() + 1);
        int n = g.size();
        
        // for(int i=0;i<adj.size();i++)
        // {
            // g[i] = adj[i];
        // }
        
        auto bfs = [&](int src){
          queue<int> q;
          q.push(src);
          
          bool vis[n];
          memset(vis,false,sizeof vis);
          
          vis[src] = true;
          
          int dist = 0;
          
          while(!q.empty())
          {
              int sz = q.size();
              for(int i=0;i<sz;i++)
              {
                  int node = q.front();
                //   cout << node << " ";
                  q.pop();
                  
                  vis[node] = true;
                  
                  for(auto &child : g[node])
                  {
                      if(!vis[child])
                        q.push(child);
                  }
              }
            //   cout <<  "\n";
              dist++;
          }
          
        //   cout << "\n";
          return dist;
        };
        
        int mini = 1e9 , house = -1;
        
        // for(int i=0;i<g.size();i++)
        // {
        //     cout << i << " -> ";
        //     for(auto &val : g[i])
        //         cout << val << " ";
        //     cout << "\n";
        // }
        
        for(int i=1;i<n;i++)
        {
            int val = bfs(i);
            // cout << "distance = " << val << "\n ";
            if(val < mini)
                mini = val , house = i;
        }
        // cout << "\n";
        return mini-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends