// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
vector<int> FindWays(vector<vector<int>>&matrix){
        int MOD = 1e9+7, n = matrix.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, {0, 0}));
        
        dp[n-1][n-1] = {1, matrix[n-1][n-1]};
        for(int i=n-2; i>=0; i--) {
            if(matrix[i][n-1] != 1)
                dp[i][n-1] = {dp[i+1][n-1][0], matrix[i][n-1]+dp[i+1][n-1][1]};
            
            if(!dp[i+1][n-1][1]) dp[i][n-1][1] = 0;
        }
        
        for(int j=n-2; j>=0; j--) {
            if(matrix[n-1][j] != 2) 
                dp[n-1][j] = {dp[n-1][j+1][0], matrix[n-1][j]+dp[n-1][j+1][1]};
            
            if(!dp[n-1][j+1][1]) dp[n-1][j][1] = 0;
        }
        
        for(int i=n-2; i>=0; i--) {
            for(int j=n-2; j>=0; j--) {
                if(matrix[i][j] == 1) dp[i][j] = {dp[i][j+1][0], 1+dp[i][j+1][1]};
                else if(matrix[i][j] == 2) dp[i][j] = {dp[i+1][j][0], 2+dp[i+1][j][1]};
                else dp[i][j] = {(dp[i+1][j][0] + dp[i][j+1][0])%MOD, 3+max(dp[i+1][j][1], dp[i][j+1][1])};
                
                if(dp[i][j][1] == matrix[i][j]) dp[i][j][1] = 0;
            }
        }
        
        if(dp[0][0][0])
            return dp[0][0];
        else return {0, 0};
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends