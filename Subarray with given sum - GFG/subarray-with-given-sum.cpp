// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int start = 0 , end = 0;
        typedef long long ll;
        ll curr = 0;
        
        while(end<n)
        {
            curr += arr[end];
            
            while(start<=end and curr>s) curr -= arr[start++];
            
            if(curr == s) return {start+1,end+1};
            end++;
        }
        
        while(start<=end and curr>s) curr -= arr[start++];
        if(curr == s) return {start+1,end+1};
        
        
        return {-1};
        
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends