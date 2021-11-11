class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        for(auto &val : nums)
        {
            sum += val;
            res = min(res,sum);
        }
        
        return abs(res)+1;
    }
};