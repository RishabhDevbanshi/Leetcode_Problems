class Solution {
    void helper(vector<int> &nums,vector<int> &ds,vector<vector<int>> &arr,int freq[])
    {
        if(ds.size() == nums.size())
        {
            arr.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                freq[i] = 1;
                ds.push_back(nums[i]);
                helper(nums,ds,arr,freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> arr;
        vector<int> ds;
        int freq[nums.size()];
        
        for(int i=0;i<nums.size();i++) freq[i] = 0;
        
        helper(nums,ds,arr,freq);
        
        return arr;
    }
};