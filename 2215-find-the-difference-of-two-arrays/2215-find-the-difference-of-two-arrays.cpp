class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        
        set<int> a(nums1.begin(),nums1.end()) , b(nums2.begin(),nums2.end());
        
        for(auto &val : a)
        {
            if(b.count(val) == 0)
                res[0].push_back(val);
        }
        
        for(auto &val : b)
        {
            if(a.count(val) == 0)
                res[1].push_back(val);
        }
        
        
        return res;
    }
};