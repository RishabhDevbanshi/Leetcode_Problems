class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<vector<int>> dp(size(nums)+1,vector<int>(size(nums)+1));
        
        for(int idx=size(nums)-1;idx>=0;idx--)
        {
            for(int pidx=idx-1;pidx>=-1;pidx--)
            {
                int len = dp[idx+1][pidx+1];
                if(pidx == -1 or nums[idx] > nums[pidx])
                 len = max(len,1 + dp[idx+1][idx+1]);
                dp[idx][pidx+1] = len;
            }
        }
        
        return dp[0][0];
    }
};