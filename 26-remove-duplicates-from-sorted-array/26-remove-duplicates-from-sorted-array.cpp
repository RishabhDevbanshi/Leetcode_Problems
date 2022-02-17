class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = -500;
        int curr = 0;
        
        for(int i=0;i<size(nums);i++)
        {
            
            if(nums[i] == prev)
                continue;
            
            prev = nums[i];
            swap(nums[i],nums[curr]);
            curr++;
        }
        
        return curr;
    }
};