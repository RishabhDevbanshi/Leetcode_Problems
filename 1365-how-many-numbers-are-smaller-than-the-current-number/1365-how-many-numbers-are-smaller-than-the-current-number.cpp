class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt;
        for(auto &val : nums)
        {
            int tot=0;
            for(auto &tmp : nums)
            {
                tot += val > tmp;
            }
            cnt.push_back(tot);
        }
        
        return  cnt;
    }
};