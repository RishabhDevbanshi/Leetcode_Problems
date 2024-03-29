// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    
	    int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];
        int half = (sum/2);
        int dp[n+1][half + 1];
        
        for(int i=0;i<=n;i++) dp[i][0] = 1; 
        for(int i=1;i<=half;i++) dp[0][i] = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=half;j++)
            {
                if(j < arr[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<=half;i++) 
        {
            if(dp[n][i])
            {
                ans = min(ans,abs(sum - 2*i));
            }
        }
        
        return ans;
	    
	    
	    
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends