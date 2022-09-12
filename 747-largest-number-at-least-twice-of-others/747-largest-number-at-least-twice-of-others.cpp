class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = max_element(nums.begin(),nums.end()) - nums.begin();
        for(auto &val : nums)
        {
            if(val == nums[maxi])
                continue;
            if(val*2 > nums[maxi])
                return -1;
        }
        
        return maxi;
    }
};