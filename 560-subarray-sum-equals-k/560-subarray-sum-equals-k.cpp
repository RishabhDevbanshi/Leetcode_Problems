class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int sum = 0;
        
        int cnt = 0;
        
        for(auto &val : nums)
        {
            sum += val;
            
            if(sum == k) cnt++;
            
            if(mp.count(sum - k))
                cnt += mp[sum - k];
            
            mp[sum]++;
        }
        
        
        return cnt;
    }
};