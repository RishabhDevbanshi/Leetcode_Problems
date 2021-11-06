class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        uint x = 0;
        vector<int> res;
        for(auto &val : nums) x ^= val;
        int r = x & (-x);
        int bucket1 = 0 , bucket2 = 0;
        for(auto &val : nums) 
        {
            if(val & r) bucket1 ^= val;
            else bucket2 ^= val;
        }
        res.push_back(bucket1);
        res.push_back(bucket2);
        return  res;
    }
};