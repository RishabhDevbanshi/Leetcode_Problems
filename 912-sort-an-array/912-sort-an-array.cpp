class Solution {
    
    void merge(vector<int> &nums,int start,int mid,int end)
    {
        int temp[end-start+1];
        
        int i=start , j=mid, k=0;
        while(i<mid and j<=end)
        {
            temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }
        
        while(i<mid)
            temp[k++] = nums[i++];
        while(j<=end)
            temp[k++] = nums[j++];
        
        k=0;
        for(i=start;i<=end;i++)
            nums[i] = temp[k++];
    }
    
    void mergeSort(vector<int> &nums,int l,int r)
    {
        if(l>=r)
            return;
        
        int mid = l + (r-l)/2;
        
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid+1,r);
    }
        
    
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,size(nums)-1);
        return nums;
    }
};