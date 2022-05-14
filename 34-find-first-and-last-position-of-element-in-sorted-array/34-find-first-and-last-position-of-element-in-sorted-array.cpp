class Solution {
    int first(vector<int> &arr,int n,int target)
    {
        int start = 0 , end = n-1;
        int ans = -1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(arr[mid] == target) ans = mid,end = mid - 1;
            else if(arr[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        
        return ans;
    }
    
    int last(vector<int> &arr,int n,int target)
    {
        int start = 0 , end = n-1;
        int ans = -1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(arr[mid] == target) ans = mid,start = mid+1;
            else if(arr[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        
        vector<int> ans(2);
        ans[0] = first(arr,arr.size(),target) , ans[1] = last(arr,arr.size(),target);
        
        return ans;
        
        
    }
};