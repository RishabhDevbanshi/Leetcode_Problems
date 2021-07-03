class Solution {
    int bs(vector<int> &nums,int start,int end)
    {
        if(start > end) return -1;
        
        if(start == end) return nums[start];
        
        int mid = start + (end - start)/2;
        
        if(mid&1)
        {
            if(nums[mid] == nums[mid-1])
                return bs(nums,mid+1,end);
            else return bs(nums,start,mid-1);
        }
        else
        {
            if(nums[mid] == nums[mid+1])
                return bs(nums,mid+2,end);
            else return bs(nums,start,mid);
        }
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        return bs(nums,0,nums.size()-1);
    }
};