// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    
	   vector<ull> dp(n);
	   dp[0] = 1;
	   ull i = 1;
	   ull two = 0 ,three = 0 , five = 0;
	   while(i < n)
	   {
	       dp[i] = min({2*dp[two],3*dp[three],5*dp[five]});
	       two += (dp[i] == 2*dp[two]);
	       three += (dp[i] == 3*dp[three]);
	       five += (dp[i] == 5*dp[five]);
	       i++;
	   }
	   
	   
	   return dp.back();
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends