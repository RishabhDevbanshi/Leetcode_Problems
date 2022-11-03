//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        sort(arr.begin(),arr.end());
        
        int mini = 1e9;
        
        for(int i=0;i<arr.size();i++)
        {
            int idx = upper_bound(arr.begin()+i,arr.end(),k+arr[i]) - arr.begin(); --idx;
            mini = min<int>(mini,i + arr.size()-idx-1);
        }
        
        return mini;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends