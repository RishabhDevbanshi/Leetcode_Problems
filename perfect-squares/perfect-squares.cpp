class Solution {
    
//     int bs(int n)
//     {
//         int start = 1, end = n;
//         int ans = -1;
        
//         while(start <= end)
//         {
//             int mid = start + (end-start)/2;
//             if(mid*mid == n)
//                 return mid*mid;
//             else if(mid < n)
//                 ans = mid , start = mid+1;
//             else 
//                 end = mid-1;
//         }
        
//         return ans;
//     }
    
    int recur(int n,vector<int> &dp)
    {
        if(n == 0) return 0;
        if(n < 0) return 1e6;
        
        if(dp[n] != -1)
            return dp[n];
        
        int res = n;
        
        for(int i=1;i<=sqrt(n);i++)
        {
            int val = i*i;
            res = min(res,1 + recur(n - val,dp));
        }
        
        return dp[n] = res;
    }
    
    
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return recur(n,dp);
    }
};