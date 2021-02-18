class Solution {
public:
    int fib(int n) {
        if(n==1 or n==0) return n;
        
        vector<long long> dp(1000);
        dp[0]=0; dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};