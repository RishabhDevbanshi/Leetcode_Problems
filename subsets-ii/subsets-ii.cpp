class Solution {
    void recur(vector<int> &nums,int n,int i,vector<int> arr,vector<vector<int>> &res)
    {
        if(i >= n)
        {
            if(find(res.begin(),res.end(),arr) == res.end()) res.push_back(arr);
            return;
        }
        
        recur(nums,n,i+1,arr,res);
        arr.push_back(nums[i]);
        recur(nums,n,i+1,arr,res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        sort(nums.begin(),nums.end());
        
        recur(nums,nums.size(),0,arr,res);
        
        return res;
    }
};