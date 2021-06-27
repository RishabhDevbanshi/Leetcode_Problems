class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 or n == 1) return n;
        
        int curr = 0 , next = 1;
        while(next < n)
        {
            if(nums[curr] != nums[next])
            {
                curr = curr+1;
                swap(nums[curr],nums[next]);
            }
            
            next++;
        }
        
        return curr+1;
    }
};