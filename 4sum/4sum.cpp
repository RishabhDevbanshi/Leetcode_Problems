class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int start = j+1, end = n-1;
                int ele = target - (nums[i] + nums[j]);
                
                while(start < end)
                {
                    int val = nums[start] + nums[end];
                    
                    if(val < ele) start++;
                    else if(val > ele) end--;
                    else
                    {
                        vector<int> arr(4);
                        arr[0] = nums[i] , arr[1] = nums[j], 
                        arr[2] = nums[start], arr[3] = nums[end];
                        ans.push_back(arr);
                        
                        //move start fwd, until we find next unique element
                        while(start < end and nums[start] == arr[2]) start++;
                        
                        //move end backward until we find next unique element
                        while(end > start and nums[end] == arr[3]) end--;
                    }
                    
                }
                
                while(j+1<n and nums[j+1] == nums[j]) ++j;
            }
            
            while(i+1<n and nums[i+1] == nums[i]) ++i;
        }
        
        return ans;
        
    }
};