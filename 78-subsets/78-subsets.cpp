class Solution {
    
    void recur(vector<int> &nums,int idx,vector<int> &arr,vector<vector<int>> &ans)
    {
        
        if(idx == size(nums))
        {
            ans.push_back(arr);
            return;
        }
        
        
        recur(nums,idx+1,arr,ans);
        arr.push_back(nums[idx]);
        recur(nums,idx+1,arr,ans);
        arr.pop_back();
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> arr;
        
        recur(nums,0,arr,ans);
        
        
        return ans;
    }
};