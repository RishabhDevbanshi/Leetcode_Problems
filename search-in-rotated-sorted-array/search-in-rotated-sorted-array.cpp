class Solution {
    int bs(vector<int> &arr,int start,int end,int ele)
    {
        if(start > end) return -1;
        
        int mid = start + (end - start)/2;
        
        if(arr[mid] == ele) return mid;
        
        int left_ans = bs(arr,start,mid-1,ele);
        if(left_ans != -1) return left_ans;
        
        return bs(arr,mid+1,end,ele);
    }
public:
    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
};