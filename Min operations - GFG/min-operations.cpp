//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        bool ok1 = false, ok2 = false;
        for(long i=31;i>=0;i--)
        {
            if(((a>>i)&1) != ((b>>i)&1))
            {
                int bit1 = ((a>>i)&1);
                int bit2 = ((b>>i)&1);
                // cout << i << " " << bit1 << " " << bit2 << "\n";
                if(((a>>i)&1)) ok1 = true;
                else ok2 = true;
            }
        }
        
        // cout << ok1 << " " << ok2 << "\n";
        
        return ok1 + ok2;
    }
};

// 5-> 0101
// 12->1100


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends