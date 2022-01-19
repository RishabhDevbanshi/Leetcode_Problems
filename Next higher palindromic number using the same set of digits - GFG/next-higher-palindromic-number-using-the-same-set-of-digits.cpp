// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        if(N.size() <= 3) return "-1";
        int mid = N.size()/2;
        string fh = N.substr(0,mid);
        
        string temp = fh;
        
        next_permutation(fh.begin(),fh.end());
        
        
        if(fh <= temp) return "-1";
        
        string res = fh;
        
        if(N.size()%2) res += N[mid];
        
        reverse(fh.begin(),fh.end());
        
        res += fh;
        
        return res;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends