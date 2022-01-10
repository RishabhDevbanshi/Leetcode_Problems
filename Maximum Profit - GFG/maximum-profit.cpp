// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
    typedef long long ll;
    ll dp[2][501][201];
    
    ll recur(int arr[],int k,int n,int idx=0,bool ok=false)
    {
        if(idx>=n || k==0)
            return 0;
            
        if(dp[ok][idx][k] != -1)
            return dp[ok][idx][k];
        
        ll sum = recur(arr,k,n,idx+1,ok);
        
        if(ok)
        {
            sum = max(sum , recur(arr,k-1,n,idx+1,false) + arr[idx]);
        }
        else
        {
            sum = max(sum , recur(arr,k,n,idx+1,true) - arr[idx]);
        }
        
        return dp[ok][idx][k] = sum;
        
    }
    
  public:
    int maxProfit(int K, int N, int A[]) {
        
        memset(dp,-1,sizeof dp);
        
        return recur(A,K,N,0,false);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends