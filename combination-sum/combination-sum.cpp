class Solution {
    void helper(vector<int> &nums,int i,int tar,vector<int> &arr,vector<vector<int>> &res)
    {
        if(i == nums.size())
        {
            if(tar == 0) res.push_back(arr);
            return;
        }
        
        if(nums[i] <= tar)
        {
            arr.push_back(nums[i]);
            helper(nums,i,tar - nums[i],arr,res);
            arr.pop_back();
        }
        
        helper(nums,i+1,tar,arr,res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> res;
        
        helper(candidates,0,target,arr,res);
        
        return res;
    }
};