class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int mx = arr[n-1];
        int res = 0;
        
        for(int i=n-2;i>=0;i--)
        {
            res = max(res,mx - arr[i]);
            mx = max(mx,arr[i]);
        }
        
        return res;
    };
};