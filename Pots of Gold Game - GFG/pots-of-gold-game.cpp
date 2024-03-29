// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int recur(vector<int> &arr,int start,int end,vector<vector<int>> &dp)
    {
        if(start > end) return 0;
        if(start == end) return arr[start];
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int op1 = arr[start] + min(recur(arr,start+2,end,dp) , recur(arr,start+1,end-1,dp));
        int op2 = arr[end] + min(recur(arr,start,end-2,dp) , recur(arr,start+1,end-1,dp));
        
        return dp[start][end] = max(op1,op2);
    }
public:
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>> dp(505,vector<int>(505,-1));
	    return recur(A,0,n-1,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends