class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int sum = 0;
        int tot = 0;
        
        for(auto &val : nums)
        {
            sum += val;
            if(sum == goal)
                tot++;
            int rem = sum - goal;
            if(mp.find(rem) != mp.end())
                tot += mp[rem];
            mp[sum]++;
        }
        
        return tot;
    }
};