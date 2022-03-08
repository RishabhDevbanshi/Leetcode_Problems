class Solution {
    
    void recur(vector<int> &nums,int idx,vector<int> &sub,vector<vector<int>> &res)
    {
        res.push_back(sub);
    
        for(int i=idx;i<size(nums);i++)
        {
            if(i != idx and nums[i] == nums[i-1])
                continue;
            sub.push_back(nums[i]);
            recur(nums,i+1,sub,res);
            sub.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> sub;
        
        recur(nums,0,sub,res);
        
        return res;
        
    }
};