#define ll long long

class Solution {
public:
    int distinctSubseqII(string str) {
        int n = str.size();
        ll* dp = new ll[n + 1]();
        dp[0] = 1;
    
        map<char,ll> mp;
        ll mod = 1e9 + 7;
    
        for(int i=1;i<=n;i++)
        {
            char ch = str[i-1];
            dp[i] = (2 * dp[i-1]) % mod;
    
            if(mp.find(ch) != mp.end())
            {
                int idx = mp[ch];
                dp[i] = (dp[i]%mod - dp[idx-1]%mod)%mod;
            }
    
            mp[ch] = i;
        }
    
        int ans = dp[n]%mod;
        ans -= 1;
        delete[] dp;
        mp.clear();
        
        if(ans < 0) return ans + mod;
        
        return ans;
    }
};