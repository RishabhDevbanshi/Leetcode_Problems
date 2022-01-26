// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    string res = "";
    
    void recur(string &str,int K,int idx,int swaps)
    {
        if(swaps == K || idx >= str.size())
        {
            return;
        }
        
        for(int i=idx+1;i<str.size();i++)
        {
            if(str[idx] > str[i]) continue;
            swap(str[idx],str[i]);
            // cout<<str<<"\n";
            res = max(res,str);
            recur(str,K,idx+1,swaps+1);
            swap(str[idx],str[i]);
        }
        
        recur(str,K,idx+1,swaps);
    }
    
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       res = str;
       recur(str,k,0,0);
       return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends