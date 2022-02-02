class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        typedef long long ll;
        
        ll sum = 0 , res = INT_MAX;
        
        deque<pair<ll,ll>> dq;
        
        int idx = 0;
        
        for(auto &val : nums)
        {
            sum += val;
            
            if(sum >= k)
                res = min(res,(ll)idx+1);
            
            pair<ll,ll> f = {INT_MIN,INT_MIN};
            
            while(!dq.empty() and sum - dq.front().second >= k)
            {
                f = dq.front();
                dq.pop_front();
            }
            
            if(f.second != INT_MIN)
                res = min(res,(ll)idx - f.first);
            
            while(!dq.empty() and sum <= dq.back().second)
                dq.pop_back();
            
            dq.push_back({idx++,sum});
        }
        
        return res == INT_MAX ? -1 : res;
    }
};