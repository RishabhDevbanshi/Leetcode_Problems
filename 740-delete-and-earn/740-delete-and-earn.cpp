class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int mx = 0;
        for(auto &val : nums)
            mp[val]++ , mx = max(mx,val);
        
        int dp[mx+1];
        memset(dp,0,sizeof dp);
        
        dp[1] = mp.count(1) ? 1*mp[1] : 0;
        
        for(int i=2;i<=mx;i++)
        {
            int val = mp.count(i) ? i*mp[i] : 0;
            dp[i] = max(dp[i-1],val + dp[i-2]);
        }
        
        for(int i=0;i<=mx;i++)
            cout<<dp[i]<<" ";
        
        return dp[mx];
    }
};