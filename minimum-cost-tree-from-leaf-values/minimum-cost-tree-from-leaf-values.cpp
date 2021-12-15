#define vi vector<int>
#define vvi vector<vi>

class Solution {
    
    int recur(int left,int right,vvi &maxi,vvi &dp)
    {
        if(left == right)
            return 0;
        
        if(dp[left][right] != -1)
            return  dp[left][right];
        
        int ans = INT_MAX;
        
        for(int i=left;i<right;i++)
        {
            int val = (maxi[left][i] * maxi[i+1][right]) + recur(left,i,maxi,dp)
                        + recur(i+1,right,maxi,dp);
            ans = min(ans,val);
        }
        
        return dp[left][right] = ans;
    }
    
    
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = size(arr);
        
        vvi maxi(n+1,vi(n+1,0)) , dp(n+1,vi(n+1,-1));
        
        for(int i=0;i<n;i++)
        {
            maxi[i][i] = arr[i];
            for(int j=i+1;j<n;j++)
            {
                maxi[i][j] = max(arr[j],maxi[i][j-1]);
            }
        }
        
        
        return recur(0,n-1,maxi,dp);
    }
};