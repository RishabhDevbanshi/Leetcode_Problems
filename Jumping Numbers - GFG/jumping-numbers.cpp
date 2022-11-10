//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        
        string curr = "" , orig = to_string(X);
        long res = 0;
        
        function<void(int)> dfs = [&](int idx){
            
            if(idx == orig.size())
            {
                // cout << curr << " " ;
                if(stol(curr) <= X)
                    res = max(res,stol(curr));
                return;
            }
            
            if(curr.size() and curr.back() == '0')
            {
                if(idx == 1)
                {
                    for(int i=1;i<=9;i++)
                    {
                        curr += '0' + i;
                        dfs(idx+1);
                        curr.pop_back();
                    }
                }
                else
                {
                    curr += '1';
                    dfs(idx+1);
                    curr.pop_back();
                }
                return;
            }
            else if(curr.size() and curr.back() == '9')
            {
                curr += '8';
                dfs(idx+1);
                curr.pop_back();
                return;
            }
            else if(curr.size() == 0)
            {
                for(int i=0;i<=orig[0] - '0';i++)
                {
                    curr += '0' + i;
                    dfs(idx+1);
                    curr.pop_back();
                }
                return;
            }
            
            curr += '0' + (curr.back() - '0') + 1;
            dfs(idx+1);
            curr.pop_back();
            curr += '0' + (curr.back() - '0') - 1;
            dfs(idx+1);
            curr.pop_back();
            return;
        };
        
        
        dfs(0);
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends