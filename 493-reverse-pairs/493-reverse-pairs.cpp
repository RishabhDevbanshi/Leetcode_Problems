class Solution {
    int cnt;
    
    void merge(vector<int> &nums,int left,int mid,int right)
    {
        int i=left,j=mid,k=0;
        int temp[right-left+1];
        
        for(i=left;i<mid;i++)
        {
            while(j<=right and 2LL*nums[j] < nums[i]) j++;
            
            cnt += (j - mid);
        }
        
        i=left,j=mid,k=0;
        while(i<mid and j<=right)
        {
            temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }
        
        while(i<mid)
            temp[k++] = nums[i++];
        while(j<=right)
            temp[k++] = nums[j++];
        
        k=0;
        for(int i=left;i<=right;i++)
            nums[i] = temp[k++];
    }
    
    void mergeSort(vector<int> &nums,int left,int right)
    {
        if(left >= right)
            return;
        
        int mid = left + (right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid+1,right);
    }
    
public:
    int reversePairs(vector<int>& nums) {
        cnt = 0;
        mergeSort(nums,0,size(nums)-1);
        return cnt;
    }
};