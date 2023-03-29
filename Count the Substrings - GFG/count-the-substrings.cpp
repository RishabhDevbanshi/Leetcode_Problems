//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            int up=0,low=0;
            for(int j=i;j<s.size();j++)
            {
                if(s[j]>='a' and s[j]<='z') low++;
                else up++;
                
                if(up == low) cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends