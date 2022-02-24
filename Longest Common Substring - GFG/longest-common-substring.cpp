// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define size(x) x.size()

class Solution{
    public:
    
    int ans = 0;
    vector<vector<int>> dp;
    
    int recur(string &a,string &b,int i=0,int j=0)
    {
        if(i == size(a) || j == size(b))
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        recur(a,b,i+1,j);
        recur(a,b,i,j+1);
        
        int val = a[i] == b[j] ? 1 + recur(a,b,i+1,j+1) : 0;
        
        ans = max(ans,val);
        
        return dp[i][j] = val;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        dp.resize(size(S1),vector<int> (size(S2),-1));
        
        ans = 0;
        
        recur(S1,S2);
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends