// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
    {
        // Code here
        //solve(N);
        long long int mod = 1e9+7;
        vector<long long int> fib;
        fib.push_back(1);
        fib.push_back(1);
        fib.push_back(2);
        for(long long int i = 3;i<N+2;i++)
        {
            fib.push_back((fib[i-1]%mod+fib[i-2]%mod)%mod);
        }
        return fib[fib.size()-1]%mod * fib[fib.size()-1]%mod;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends