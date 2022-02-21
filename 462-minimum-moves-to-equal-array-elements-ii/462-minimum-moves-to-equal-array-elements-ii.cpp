class Solution {
public:
    int minMoves2(vector<int>& nums) {
        typedef long long ll;
        ll sum = 0;
        ll prev_sum = 0;
        
        sort(nums.begin(),nums.end());
        
        for(auto &val : nums) sum += val;
        
        ll mini = -1, n = size(nums);
        
        for(ll i=0;i<size(nums);i++)
        {
            sum -= nums[i];
            ll op = (1LL*nums[i]*i - prev_sum) + (sum - 1LL*nums[i]*(n-1-i));
            mini = mini == -1 ? op : min(mini,op);
            prev_sum += nums[i];
        }
        
        return mini;
    }
};