class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int tot = 0;
        
        for(auto &val : nums) if(val%2 == 0) tot += val;
        // cout << tot << "\n";
        
        for(auto &q : queries)
        {
            if(nums[q[1]]%2 == 0) tot -= nums[q[1]];
            nums[q[1]] += q[0];
            // for(auto &val : nums) cout << val << " "; cout << "\n";
            if(abs(nums[q[1]])%2 == 0) tot += nums[q[1]];
            res.push_back(tot);
        }
        
        return res;
    }
};