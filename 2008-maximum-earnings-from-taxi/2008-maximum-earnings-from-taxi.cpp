class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        typedef long long ll;
        typedef pair<ll,ll> pll;
        vector<vector<pll>> mp(n);
        
        for(auto &ride : rides)
        {
            int s = ride[0] , e = ride[1] , p = ride[2];
            mp[s].push_back({e , e - s + p});
        }
        
        vector<ll> dp(n+1,0);
        
        for(int i=n-1;i>=1;i--)
        {
            for(auto &[e,d] : mp[i])
            {
                dp[i] = max(dp[i],dp[e] + d);
            }
            
            dp[i] = max(dp[i],dp[i+1]);
        }
        
        
        return dp[1];
    }
};