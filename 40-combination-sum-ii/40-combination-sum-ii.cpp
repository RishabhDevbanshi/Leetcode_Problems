class Solution {
    void recur(vector<int> &nums,int idx,int tar,vector<int> &com,vector<vector<int>> &res) 
    {
        if(tar < 0)
            return;
        
        if(tar == 0)
        {
            res.push_back(com);
            return;
        }
        
        for(int i=idx;i<size(nums);i++)
        {
            if(i != idx and nums[i] == nums[i-1])
                continue;
            com.push_back(nums[i]);
            recur(nums,i+1,tar - nums[i],com,res);
            com.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> com;
        sort(candidates.begin(),candidates.end());
        
        recur(candidates,0,target,com,res);
        
        return res;
    }
};