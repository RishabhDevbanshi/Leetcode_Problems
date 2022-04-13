// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    
	    vector<vector<int>> dp(nums.size()+1,vector<int>(amount+1,-1));
	    
	    function<int(int,int)> recur = [&](int idx,int amt){
	        if(amt == 0)
	            return 0;
    	      if(idx == nums.size())
    	        return (int)1e7;
    	        
    	       if(dp[idx][amt] != -1)
    	            return dp[idx][amt];
	       
	       if(amt < nums[idx])
	        return dp[idx][amt] = recur(idx+1,amt);
	       
	       return dp[idx][amt] = min(recur(idx+1,amt) , 1 + recur(idx,amt - nums[idx]));
	    };
	    
	    int ans = recur(0,amount);
	    
	    return ans == (int)1e7 ? -1 : ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends