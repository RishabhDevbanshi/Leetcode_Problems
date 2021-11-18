class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int val = 2*n;
        
        for(auto &ele : nums)
        {
            int idx = (ele%val) - 1;
            if(nums[idx]/val == 0) nums[idx] += val;
        }
        
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(nums[i]/val == 0) res.push_back(i+1);
        }
        
        return res;
    }
};