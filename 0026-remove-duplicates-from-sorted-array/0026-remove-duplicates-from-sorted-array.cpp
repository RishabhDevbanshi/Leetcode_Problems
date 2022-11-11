class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int idx = 1;
        for(int i=1;i<size(nums);i++)
        {
            if(nums[i] == prev)
                continue;
            
            prev = nums[i];
            nums[idx++] = nums[i];
        }
        
        return idx;
    }
};