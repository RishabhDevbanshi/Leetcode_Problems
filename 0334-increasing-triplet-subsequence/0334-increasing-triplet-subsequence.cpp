class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        multiset<int> a,b;
        for(auto &val : nums)
            b.insert(val);
        for(auto &val : nums)
        {
            b.erase(b.find(val));
            if(size(a) and *a.begin() < val and size(b) and *--b.end() > val)
                return true;
            a.insert(val);
        }
        
        return false;
    }
};