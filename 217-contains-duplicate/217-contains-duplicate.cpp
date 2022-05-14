class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &val : nums)
        {
            if(mp.find(val) != mp.end())
                return true;
            mp[val]++;
        }
        
        return false;
    }
};