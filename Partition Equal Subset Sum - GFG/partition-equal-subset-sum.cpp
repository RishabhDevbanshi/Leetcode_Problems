// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    int recur(int arr[],int N,int idx,int sum,vector<vector<int>> &dp)
    {
        if(sum == 0) return 1;
        else if(idx == N) return 0;
        
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        if(sum < arr[idx])
            return dp[idx][sum] = recur(arr,N,idx+1,sum,dp);
        else
            return dp[idx][sum] = recur(arr,N,idx+1,sum,dp) || recur(arr,N,idx+1,sum - arr[idx],dp);
    }
    
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++) sum += arr[i];
        
        if(sum&1) return false;
        
        int half = sum/2;
        
        vector<vector<int>> dp(N+1,vector<int>(half+1,-1));
        
        return recur(arr,N,0,half,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends