// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends


vector<int> permute(vector<vector<int>> &arr, int n)
{
    vector<int> res;
    
    for(int i=0;i<arr.size();i++)
    {
        arr[i][1] = arr[i][0] + arr[i][1];
        arr[i].push_back(i+1);
    }
    
    sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
        if(a[1] == b[1])
            return a[2] < b[2];
        return a[1] < b[1];
    });
    
    for(auto &val : arr)
        res.push_back(val[2]);
    
    return res;
}