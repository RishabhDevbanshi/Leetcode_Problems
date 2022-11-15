//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        multiset<int> st;
        
        int len = 0;
        
        int start=0,end=0;
        
        while(end < N)
        {
            st.insert(arr[end++]);
            while(start < end and *--st.end() - *st.begin() > 1)
            {
                st.erase(st.find(arr[start]));
                start++;
            }
            // cout << start << " " << end << "\n";
            len = max(len,end-start);
        }
        
        return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends