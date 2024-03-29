// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<=1) return n;
        int res = 2;
        
        vector<vector<int>> dp(n+1,vector<int>(1e4 + 5));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff = A[i] - A[j];
                dp[i][diff] = dp[j][diff] == 0 ? 2 : dp[j][diff]+1;
                res = max(res,dp[i][diff]);
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends