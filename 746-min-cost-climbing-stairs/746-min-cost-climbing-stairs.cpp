class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = 0 , b = INT_MAX;
        
        for(int i=n-1;i>=0;i--)
        {
            int curr = cost[i] + min(a,b);
            b = a, a = curr;
        }
        
        return min(a,b);
    }
};