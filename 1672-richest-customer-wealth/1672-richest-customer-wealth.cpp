class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = 0;
        for(auto &v : accounts)
        {
            int wealth = 0;
            for(auto &val : v)
                wealth += val;
            mx = max(mx,wealth);
        }
        
        return mx;
    }
};