class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        multiset<int> b;
        for(auto &val : nums)
            b.insert(val);
        int mini = nums[0];
        for(auto &val : nums)
        {
            b.erase(b.find(val));
            if(mini < val and size(b) and *--b.end() > val)
                return true;
            // a.insert(val);
            mini = min(mini,val);
        }
        
        return false;
    }
};