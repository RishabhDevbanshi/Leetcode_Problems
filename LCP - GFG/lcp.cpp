// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

#define size(x) x.size()

class Solution{
public:
    string LCP(string ar[], int n)
    {
        if(n == 1)
            return ar[0];
        
        sort(ar,ar+n,[&](string &a,string &b){
            return a<b;
        });
        
        string res = "";
        int i=0 ,j=0;
        while(i<size(ar[0]) and j<size(ar[n-1]))
        {
            if(ar[0][i] == ar[n-1][j])
                res += ar[0][i] , i++ , j++;
            else
                break;
        }
        
        return size(res) > 0 ? res : "-1";
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
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends