//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        string str = "";
        for(auto &ch : s)
        {
            if(str.size() == 0 or ch != str.back())
                str += ch;
            else
                str.pop_back();
        }
        
        return str.size() ? str : "-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends