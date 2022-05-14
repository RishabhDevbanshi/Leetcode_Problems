class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0 , maxi = nums[0];
        for(auto &val : nums)
        {
            curr += val;
            maxi = max(maxi,curr);
            curr = max(curr,0);
        }
        
        return maxi;
    }
};