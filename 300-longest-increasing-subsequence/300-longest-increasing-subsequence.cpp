class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(size(nums)+1);
        
        for(int idx=size(nums)-1;idx>=0;idx--)
        {
            vector<int> ndp(size(nums)+1);
            for(int pidx=idx-1;pidx>=-1;pidx--)
            {
                int len = dp[pidx+1];
                if(pidx == -1 or nums[idx] > nums[pidx])
                 len = max(len,1 + dp[idx+1]);
                ndp[pidx+1] = len;
            }
            dp = ndp;
        }
        
        return dp[0];
    }
};