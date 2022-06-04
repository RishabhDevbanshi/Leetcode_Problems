// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        vector<vector<int>> g(N+1);
        vector<int> in(N+1);
        
        for(int i=0;i<M;i++)
        {
            g[mat[i][0]].push_back(mat[i][1]);
            in[mat[i][1]]++;
        }
        
        queue<int> q;
        for(int i=1;i<=N;i++)
            if(in[i] == 0)
                q.push(i);
        
        int cnt = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int node = q.front();
                q.pop();
                
                for(auto &child : g[node])
                {
                    in[child]--;
                    if(in[child] == 0)
                        q.push(child);
                }
            }
            
            cnt++;
        }
        
        return cnt;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends