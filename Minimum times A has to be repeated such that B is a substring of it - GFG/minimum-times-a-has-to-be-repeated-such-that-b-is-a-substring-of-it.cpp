//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        string tmp = "";
        // if(tmp.find(B) != string::npos)
            // return 0;
        int cnt=0;
        while(tmp.size() <= 2*B.size())
        {
            cnt++;
            tmp += A;
            if(tmp.find(B) != string::npos)
            {
                // cout << tmp << " ";
                return cnt;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends