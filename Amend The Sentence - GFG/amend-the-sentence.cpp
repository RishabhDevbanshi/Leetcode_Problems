// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define size(x) x.size()

class Solution{
    public:
    string amendSentence (string s)
    {
        string res = "";
        string str = "";
        
        for(auto &ch : s)
        {
            if(ch>='a' and ch<='z') str += ch;
            else
            {
                if(size(str) > 0)
                {
                    if(size(res) > 0) res += " " + str;
                    else res += str;
                }
                
                int gap = ch - 'A';
                char x = 'a' + gap;
                str = "";
                str += x;
            }
        }
        
        if(size(str) > 0)
            {
                if(size(res) > 0) res += " " + str;
                else res += str;
            }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends