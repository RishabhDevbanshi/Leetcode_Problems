class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt = 0;
        for(auto &cost : costs)
        {
            if(cost > coins)
                break;
            coins -= cost;
            cnt++;
        }
        
        return cnt;
    }
};