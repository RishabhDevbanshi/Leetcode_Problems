class Solution {
private:
    long long global,local;
    
    void merge(vector<int> &nums,int left,int mid,int right)
    {
        int i=left,j=mid,k=0;
        for(i=left;i<mid;i++)
        {
            while(j<=right and nums[j] < nums[i])
                j++;
            
            global += (j - mid);
        }
        
        int temp[right-left+1];
        i=left,j=mid,k=0;
        
        while(i<mid and j<=right)
        {
            if(nums[i]<nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
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
        
        int mid = left + (right - left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid+1,right);
    }
    
public:
    bool isIdealPermutation(vector<int>& nums) {
        local = 0,global = 0;
        for(int i=0;i<size(nums)-1;i++)
            local += nums[i] > nums[i+1];
        
        mergeSort(nums,0,size(nums)-1);
        
        return local == global;
    }
};