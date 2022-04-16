// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[510];
       int n;
       int rec(int i,int k,vector<int>& v){
       		//base case
           if(i<0)return 0;
           //check if already calculated
           if(dp[i]!=-1)return dp[i];
           int cost = 0,ans=1e9,pref=0;
           //transitions
           for(int j=i;j>=0;j--){
               pref+=v[j];
               if((pref+(i-j))<=k){
                   if(i!=(n-1)){
                       cost = (k-(pref+i-j))*(k-(pref+i-j));
                   }
                   ans = min(ans,rec(j-1,k,v)+cost);
               }
           }
           return dp[i] = ans;
       }


    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
       n = nums.size();
       return rec(n-1,k,nums);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends