class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int div = 2*n;
        
        for(auto &val : nums)
        {
            int idx = (val%div)-1;
            nums[idx] += div;
        }
        
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(nums[i]/div > 1) res.push_back(i+1);
        }
        
        return res;
    }
};