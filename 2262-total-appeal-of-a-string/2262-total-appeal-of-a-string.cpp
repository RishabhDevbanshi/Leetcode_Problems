class Solution {
public:
    long long appealSum(string s) {
        vector<long> lastIdx(26,-1);
        vector<long> dp(size(s)+1);
        
        long ans = 0;
        
        for(int i=0;i<size(s);i++)
        {
            int idx = s[i] - 'a';
            dp[i+1] = dp[i] + i - lastIdx[idx];
            
            ans += dp[i+1];
            
            lastIdx[idx] = i;
        }
        
        return ans;
    }
};