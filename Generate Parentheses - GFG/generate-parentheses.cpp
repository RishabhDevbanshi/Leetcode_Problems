// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    void recur(int op,int cl,int n,string &str,vector<string> &res)
    {
        if(op == n and cl == n)
        {
            res.push_back(str);
            return;
        }
        
        if(op<n)
        {
            str += '(';
            recur(op+1,cl,n,str,res);
            str.pop_back();
        }
        
        if(op >= cl+1)
        {
            str += ')';
            recur(op,cl+1,n,str,res);
            str.pop_back();
        }
    }
    
    public:
    vector<string> AllParenthesis(int n) 
    {
        string str = "";
        vector<string> res;
        
        recur(0,0,n,str,res);
        
        return res;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends