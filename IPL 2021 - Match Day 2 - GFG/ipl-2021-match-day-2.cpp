// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        
        vector<int> res;
        
        deque<int> q;
        for(int  i=0;i<k;i++) 
        {
            while(!q.empty() and q.back()<arr[i])
            {
                q.pop_back();
            }
            q.push_back(arr[i]);
        }
        
        res.push_back(q.front());
        
        int start = 0;
        
        for(int i=k;i<n;i++)
        {
            if(q.front() == arr[start++]) q.pop_front();
            while(!q.empty() and q.back()<arr[i]) q.pop_back();
            q.push_back(arr[i]);
            res.push_back(q.front());
        }
        
        
        return res;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends