// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string str ,int Q, int index[], string sources[], string targets[]) {
        int i=0 , j = 0;
        string temp = "";
        while(i<str.size())
        {
            if(i == index[j])
            {
                // cout << i << " ";
                // cout << str.substr(index[j],sources[j].size()) << "\n";
                if(str.substr(index[j],sources[j].size()) == sources[j])
                {
                    temp += targets[j];
                    i += sources[j++].size();
                }
                else
                    temp += str[i++] , j++;
            }
            else
                temp += str[i++];
        }
        
        return temp;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends