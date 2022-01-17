// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        vector<string> res;
        int mx = -1;
        
        for(auto it : mp)
        {
            string key = it.first;
            int val = it.second;
            
            if(mx < val)
            {
                mx = val;
                res = {key,to_string(val)};
            }
            else if(mx == val) res[0] = min(res[0],key);
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends