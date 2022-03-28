class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0 , end = size(nums)-1;
        while(start <= end)
        {
            int mid = (start + end)>>1;
            if(nums[mid] == target)
                return true;
            
            //ambiguous
            if(nums[start] == nums[mid] and nums[mid] == nums[end])
                start++ , end--;
            //left is sorted
            else if(nums[mid] <= nums[end])
            {
                if(nums[mid]<target and target<=nums[end])
                    start = mid+1;
                else
                    end = mid - 1;
                
            }
            else // right is sorted
            {
                if(nums[start] <= target and target < nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }
            
            
        }
        
        
        return false;
    }
};