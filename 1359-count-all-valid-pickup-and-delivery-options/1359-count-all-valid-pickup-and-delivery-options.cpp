class Solution {
    
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;
    
    int recur(int unpick,int undeliver)
    {
        if(unpick == 0 and undeliver == 0)
            return 1;
        if(unpick<0 || undeliver<0 || undeliver < unpick)
            return 0;
        
        if(dp[unpick][undeliver] != -1)
            return dp[unpick][undeliver];
        
        long long ans = 0;
        
        long long a = ((1LL*unpick)%mod * recur(unpick-1,undeliver)%mod)%mod;
        long long b = ((1LL*(undeliver - unpick))%mod * recur(unpick,undeliver-1)%mod)%mod;
        
        ans = (ans%mod + a%mod + b%mod)%mod;
        
        return dp[unpick][undeliver] = ans;
        
        
        
    }
    
public:
    int countOrders(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        
        return recur(n,n);
        
    }
};