// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    #define ll long long
    
    ll recur(int n,int x,ll idx,ll limit,vector<vector<ll>> &dp)
    {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(idx > limit+1) return 0;
        
        if(dp[idx][n] != -1)
            return dp[idx][n];
        
        ll val = pow(idx,x);
        
        return dp[idx][n] = recur(n,x,idx+1,limit,dp) + recur(n-val,x,idx+1,limit,dp);
    }
    
    public:
    ll numOfWays(int n, int x)
    {
        ll limit = pow(n,1.0/x);
        vector<vector<ll>> dp(limit+2,vector<ll>(n+1,-1));
        
        return recur(n,x,1LL,limit,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends