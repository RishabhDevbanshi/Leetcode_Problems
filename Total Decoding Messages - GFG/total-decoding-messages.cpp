//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    vector<int> dp(str.size()+1,-1);
		    
		    const int mod = 1e9 + 7;
		    
		    function<int(int)> dfs = [&](int idx){
		        if(idx >= str.size())
		            return 1;
		        if(dp[idx] != -1)
		            return dp[idx];
		        int ans = 0;
		        ans = dfs(idx+1);
		        if(str[idx] == '0')
		        {
		            return dp[idx] = 0;
		        }
		        else if(str[idx] == '1')
		        {
		            if(idx+1 < str.size())
		                ans = (ans%mod + dfs(idx+2)%mod)%mod;
		        }
		        else if(str[idx] == '2')
		        {
		            if(idx+1 < str.size() and str[idx+1] >= '0' and str[idx+1] <= '6')
		                ans = (ans%mod + dfs(idx + 2)%mod)%mod;
		        }
		        
		        return dp[idx] = ans%mod;
		    };
		    
		    return dfs(0);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends