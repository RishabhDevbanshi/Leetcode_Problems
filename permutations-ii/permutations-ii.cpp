class Solution {
    void permute(vector<int> nums,vector<vector<int>> &res,int l,int r)
    {
        if(l == r)
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=l;i<=r;i++)
        {
            if(i != l and nums[i] == nums[l]) continue;
            
            swap(nums[l],nums[i]);
            permute(nums,res,l+1,r);
            // swap(nums[l],nums[i]);
            
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        permute(nums,res,0,nums.size()-1);
        
        return res;
    }
};