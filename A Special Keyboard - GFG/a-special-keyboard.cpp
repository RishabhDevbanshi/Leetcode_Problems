// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        
        int freq[26];
        
        int i = 0;
        
        for(auto &ch : S1)
            freq[ch - 'a'] = i++;
            
        int cnt = 0;
        int idx = 0;
        for(auto &ch : S2)
        {
            cnt += abs(idx - freq[ch - 'a']);
            idx = freq[ch - 'a'];
        }
        
        return cnt;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends