class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto &ele : nums)
        {
            if(nums[abs(ele) - 1] < 0) return abs(ele);
            nums[abs(ele)-1] *= -1;
        }
        
        return 0;
    }
};