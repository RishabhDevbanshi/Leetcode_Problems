#define ll long long 
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& jobs) 
    {
        for(auto &x:jobs) x[2] += x[1]-x[0];
        
        map<ll,ll> dp;
        
        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        ll maxT = 0;
        for (auto job : jobs) {
            auto it = dp.lower_bound(job[1]);
            ll pre = (it == dp.end()) ? 0 : it->second;
            maxT = max(maxT, job[2] + pre);
            dp[job[0]] = maxT;
        }
        
        return maxT;
        
    }
};