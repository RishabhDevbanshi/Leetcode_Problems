// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string> st;
        
        for(auto &word : dict)
        {
            st.insert(word);
        }
        
        vector<string> res;
                
        vector<string> tmp;
        
        function<void(int)> dfs = [&](int idx){
            
            if(idx == s.size())
            {
                string pos = "";
                for(auto &ele : tmp) pos += ele , pos += ' ';
                pos.pop_back();
                res.push_back(pos);
                return;
            }
            
            string str = "";
            
            for(int i=idx;i<s.size();i++)
            {
                str += s[i];
                if(st.find(str) != st.end())
                {
                    tmp.push_back(str);
                    dfs(i+1);
                    tmp.pop_back();
                }
            }
            
        };
        
        
        dfs(0);
        
        return res;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends