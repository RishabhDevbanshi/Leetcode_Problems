// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rr(string s){
       string st;
       bool toPop=false;
       for(int i=0;i<s.size();i++){
           if(st.empty())
           st.push_back(s[i]);
           else if(st.back()==s[i]){
               toPop = true;
           }else if(toPop){
               st.pop_back();
               st.push_back(s[i]);
               toPop=false;
           }else{
               st.push_back(s[i]);
           }
       }
       if(toPop)
       st.pop_back();
       return st;
   }
   
   string rremove(string s){
       string itr1=rr(s),itr2="";
       while(itr1.size()!=itr2.size()){
           itr2=itr1;
           itr1=rr(itr2);
       }
       return itr2;
   }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends