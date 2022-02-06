class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool lock = false;
        
        int i=0 , prev = -1;
        for(int j=0;j<size(nums);j++)
        {
            if(prev != nums[j])
                nums[i++] = nums[j] , lock = false;
            else 
            {
                if(lock) continue;
                else nums[i++] = nums[j] , lock = true;
            }
            
            prev = nums[j];
        }
        
        return i;
    }
};