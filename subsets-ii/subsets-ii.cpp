class Solution {
    void helper(int idx,vector<int> &nums,vector<int> &arr,vector<vector<int>> &res)
    {
        res.push_back(arr);
        for(int i=idx;i<nums.size();i++)
        {
            if(i != idx and nums[i] == nums[i-1]) continue;
            arr.push_back(nums[i]);
            helper(i+1,nums,arr,res);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> arr; vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        helper(0,nums,arr,res);
        
        return res;
    }
};