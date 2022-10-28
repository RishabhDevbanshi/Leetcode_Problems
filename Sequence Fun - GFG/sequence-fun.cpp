//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    const int mod = 1e9 + 7;
		    
		    long res = 1 , pos = 1;
		    
		    while(n--)
		    {
		        res = (res * pos) + 1;
		        res %= mod;
		        pos++;
		    }
		    
		    
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends