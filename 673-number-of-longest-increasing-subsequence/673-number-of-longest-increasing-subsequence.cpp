class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> dp(size(nums),{1,1});
        
        int maxi = 0;
        
        for(int i=0;i<size(nums);i++)
        {
            int len=1 , cnt=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j] and len < 1+dp[j].first)
                    len = 1+dp[j].first , cnt = dp[j].second;
                else if(nums[i] > nums[j] and len == 1+dp[j].first)
                    cnt += dp[j].second;
            }
            
            dp[i] = {len,cnt};
            maxi = max(maxi,len);
        }
        
        int tot=0;
        
        for(auto &[len,cnt] : dp)
            if(len == maxi) tot += cnt;
        
        return tot;
    }
};