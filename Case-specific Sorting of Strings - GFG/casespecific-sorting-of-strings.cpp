//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<vector<char>> chars(2);
        for(auto &ch : str)
        {
            if(ch>='a' and ch<='z')
                chars[0].push_back(ch);
            else
                chars[1].push_back(ch);
        }
        
        sort(chars[0].begin(),chars[0].end());
        sort(chars[1].begin(),chars[1].end());
        int f=0,s=0;
        
        string res="";
        
        for(auto &ch : str)
        {
            if(ch>='a' and ch<='z')
                res += chars[0][f++];
            else
                res += chars[1][s++];
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends