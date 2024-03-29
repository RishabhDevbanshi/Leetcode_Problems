// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    
    void recur(vector<int> &arr,int idx,vector<int> &res,int sum = 0)
    {
        if(idx == arr.size())
        {
            res.push_back(sum);
            return;
        }
        
        recur(arr,idx+1,res,sum);
        recur(arr,idx+1,res,sum + arr[idx]);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        recur(arr,0,res);
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends