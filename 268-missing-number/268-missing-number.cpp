class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(auto &val : nums)
            res ^= val;
        for(int i=0;i<=size(nums);i++)
            res ^= i;
        
        return res;
    }
};