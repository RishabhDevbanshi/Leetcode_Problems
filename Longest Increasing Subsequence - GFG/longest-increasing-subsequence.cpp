// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define size(x) x.size()

class Solution
{
    int findIndex(vector<int> &lis,int tar)
    {
        int start = 0 ,end = size(lis)-1;
        int ans = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(lis[mid] > tar) ans = mid , end = mid-1;
            else if(lis[mid] == tar) return mid;
            else start = mid+1;
        }
        
        return ans;
    }
    
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> lis;
       lis.push_back(a[0]);
       
       for(int i=1;i<n;i++)
       {
            if(a[i] > lis.back()) lis.push_back(a[i]);
            else
            {
                int idx = findIndex(lis,a[i]);
                if(idx != -1) lis[idx] = a[i];
            }
       }
    //   for(auto &val : lis) cout<<val<<" ";
       
       return size(lis);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends