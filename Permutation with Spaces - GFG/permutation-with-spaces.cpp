// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
public:

    vector<string> permutation(string S){
        vector<string> res;
        
        string str = ""; str += S.front();
        
        function<void(int , bool)> perm = [&](int idx,bool ok){
            if(idx == S.size())
            {
                res.push_back(str);
                return;
            }
            
            if(!ok)
            {
                str += ' ';
                perm(idx,true);
                str.pop_back();
            }
                    
            str += S[idx];
            perm(idx+1,false);
            str.pop_back();
        };
        
        perm(1,false);
        
        return res;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends