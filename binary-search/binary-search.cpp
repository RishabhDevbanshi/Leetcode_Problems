class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            int val = nums[mid];
            
            if(val == target) return mid;
            else if(val < target) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
};