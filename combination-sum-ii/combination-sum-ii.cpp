class Solution {
    
    void helper(vector<int> &nums,int i,int target,vector<int> &arr,vector<vector<int>> &res)
    {
        if(i == nums.size())
        {
            if(target == 0) res.push_back(arr);
            return;
        }
        
        if(target < 0) return;
        if(target == 0) {res.push_back(arr); return;}
        
        for(int j=i;j<nums.size();++j)
        {
            if(j != i and nums[j] == nums[j-1]) continue;
            
            arr.push_back(nums[j]);
            helper(nums,j+1,target - nums[j],arr,res);
            arr.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> res;
        
        sort(candidates.begin(),candidates.end());
        
        helper(candidates,0,target,arr,res);
        
        return res;
    }
};