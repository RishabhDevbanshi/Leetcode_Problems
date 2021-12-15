class Solution {
    int recur(vector<int> &nums,int tar,int idx,vector<vector<int>> &dp)
    {
        if(idx == size(nums))
            return tar == 0;
        
        if(dp[idx][tar] != -1)
            return dp[idx][tar];
        
        if(nums[idx] > tar)
            return dp[idx][tar] = recur(nums,tar,idx+1,dp);
        
        return dp[idx][tar] = recur(nums,tar,idx+1,dp)
                                + recur(nums,tar - nums[idx],0,dp);
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(size(nums)+1,vector<int>(target+1,-1));
        return recur(nums,target,0,dp);
    }
};