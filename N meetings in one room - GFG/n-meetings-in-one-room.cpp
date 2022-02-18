// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define size(x) x.size()

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({start[i],end[i]});
        }
        
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        
        int cnt = 1 , prev = arr[0][1];
        
        for(int i=1;i<size(arr);i++)
        {
            if(arr[i][0] > prev)
                prev = arr[i][1] , cnt++;
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends