//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  long long largestSumCycle(int N, vector<int> Edge)
  {
      vector<bool> vis(N) , dfs_vis(N);
      
      long maxi = -1;
      
      function<void(int)> dfs = [&](int node){
            vis[node] = dfs_vis[node] = true;
            
            if(Edge[node] != -1)
            {
                int next = Edge[node];
                if(!vis[next])
                    dfs(next);
                else if(dfs_vis[next])
                {
                    int curr = next;
                    long sum = 0;
                    do{
                        sum += curr;
                        curr = Edge[curr];
                    }while(curr != next);
                   maxi = max(maxi,sum);
                }
            }
            
            dfs_vis[node] = false;
      };
      
      for(int i=0;i<N;i++)
      {
          if(!vis[i])
            dfs(i);
      }
      
      return maxi;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends