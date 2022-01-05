// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        
        stack<int> st;
        string ans = "";
        int num = 1;
        for(auto &ch : S)
        {
            st.push(num++);
            if(ch == 'I')
            {
                while(!st.empty())
                {
                    ans += ('0' + st.top());
                    st.pop();
                }
            }
        }
        
        st.push(num);
        
        while(!st.empty())
        {
            ans += ('0' + st.top());
            st.pop();
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends