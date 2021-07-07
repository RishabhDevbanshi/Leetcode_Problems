class Solution {
    int recur(vector<int> &nums,int i,int target)
    {
        if(i == nums.size())
        {
            return target == 0;
        }
        
        return recur(nums,i+1,target-nums[i]) + recur(nums,i+1,target+nums[i]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        return recur(nums,0,target);
    }
};