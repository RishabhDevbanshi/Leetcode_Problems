class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int curr=0;
        mp[0]=1;
        
        int cnt=0;
        
        for(auto &ele : nums)
        {
            curr = (curr + ele%k + k)%k;
            cnt += mp[curr]++;
        }
        
        
        return cnt;
    }
};