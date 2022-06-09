class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0 , end = size(nums)-1;
        while(start < end)
        {
            int val = nums[start] + nums[end];
            if(val == target)
                return {start+1,end+1};
            else if(val < target)
                start++;
            else
                end--;
        }
        
        return {};
    }
};