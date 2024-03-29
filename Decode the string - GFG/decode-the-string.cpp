// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<string> st;
        for(auto &ch : s)
        {
            if(ch != ']') 
            {
                string str; str.push_back(ch);
                st.push(str);
            }
            else
            {
                vector<string> v;
                while(!st.empty() and st.top() != "[") 
                {
                    v.push_back(st.top());
                    st.pop();
                }
                reverse(v.begin(),v.end());
                st.pop();
                string number = "";
                while(!st.empty() and st.top()>="0" and st.top()<="9")
                {
                    number += st.top();
                    st.pop();
                }
                reverse(number.begin(),number.end());
                // cout<<number<<" ";
                int val = stoi(number);
                // cout<<val<<"\n";
                string comb = "";
                for(auto &ch : v) comb += ch;
                string y = "";
                for(int i=0;i<val;i++) y += comb;
                st.push(y);
            }
        }
        
        return st.top();
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends