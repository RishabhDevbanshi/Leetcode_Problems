class Solution {
public:
    int arrangeCoins(int n) {
        long long coins = 0;
        int ans = 0;
        int start = 0, end = n;
        while(start <= end)
        {
            long long mid = start + (end-start)/2;
            coins = (mid * (mid+1))/2;
            if(coins > n) end = mid-1;
            else ans = mid , start = mid+1;
        }
        
        return ans;
    }
};