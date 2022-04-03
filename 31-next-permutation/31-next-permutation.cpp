class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
       if(size(nums) == 1)
            return;
        
        int i = size(nums)-2;
        while(i>=0 and nums[i]>=nums[i+1])
            i--;
        
        if(i < 0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int j=size(nums)-1;j>i;j--)
        {
            if(nums[i] < nums[j])
            {
                swap(nums[i],nums[j]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
        
        // sort(nums.begin() + i ,nums.end());
    }
};