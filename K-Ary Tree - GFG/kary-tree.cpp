// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long karyTree(int k, int m) {
        
        const int mod = 1e9 + 7;
        
        function<long(long ,long)> calc = [&](long x,long y)->long{
            if(y == 0)
                return 1LL;
            long temp = calc(x,y/2)%mod;
            temp = (temp%mod * temp%mod);
            return y%2 ? (temp%mod * x%mod)%mod : temp%mod;
        };
        
        
        return calc(k,m)%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends