class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = 0;
        for(auto &v : accounts)
        {
            int wealth = 0;
            for(auto &ele : v) wealth += ele;
            sum = max(sum,wealth);
        }
        
        return sum;
    }
};