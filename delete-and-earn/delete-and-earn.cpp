class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        
        unordered_map<int,int> mp;
        int mx = 0;
        
        for(auto &val : nums)
            mp[val]++ , mx = max(mx,val);
        
        int n = size(nums);
        int dp[mx+1];
        
        dp[0] = 0;
        dp[1] = mp.find(1) == mp.end() ? 0 : mp[1];
        
        for(int i=2;i<=mx;i++)
        {
            int val = mp.find(i) == mp.end() ? 0 : i * mp[i];
            dp[i] = max(dp[i-1] , val + dp[i-2]);
        }
        
        return  dp[mx];
    }
};