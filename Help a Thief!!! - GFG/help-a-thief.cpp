// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        vector<vector<int>> arr;
        
        for(int i=0;i<N;i++)
            arr.push_back({A[i],B[i]});
        
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
            long double f = (1.0*a[1])/a[0];
            long double s = (1.0*b[1])/b[0];
            
            return a[1] > b[1];
        });
        
        int tot = 0;
        for(int i=0;i<N and T>0;i++)
        {
            int take = min(T,arr[i][0]);
            T -= take;
            tot += (take * arr[i][1]);
        }
        
        
        return tot;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends