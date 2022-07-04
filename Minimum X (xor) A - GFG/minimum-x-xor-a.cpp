// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int cnt = 0;
        for(long i=31;i>=0;i--)
        {
            if((b>>i)&1) cnt++;
        }
        
        long ans = 0;
        for(int i=31;i>=0 and cnt;i--)
        {
            if((a>>i)&1) ans += 1LL<<i , cnt--;
        }
        
        for(int i=0;i<=31 and cnt;i++)
        {
            // cout << ((ans>>i)&1) << "\n";
            if(!((ans>>i)&1)) {ans += 1LL<<i , cnt--;}
        }
       
        // cout << "cnt = " << cnt << "\n";
        
        return ans;
    }
};

// 9 -> 1001
// x -> 1011
// 7 -> 0111
     


// 12 -> 1100

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends