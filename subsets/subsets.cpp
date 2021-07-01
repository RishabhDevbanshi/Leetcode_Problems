class Solution {
    
    void helper(vector<int> &nums,int idx,vector<int> &arr,vector<vector<int>> &res)
    {
        res.push_back(arr);
        for(int i=idx;i<nums.size();i++)
        {
            arr.push_back(nums[i]);
            helper(nums,i+1,arr,res);
            arr.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        
        helper(nums,0,arr,res);
        
        return res;
    }
};