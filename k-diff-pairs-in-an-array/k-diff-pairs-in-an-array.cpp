class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int cnt = 0;
        
        if(k == 0)
        {
            for(int i=0;i<n;i++) mp[nums[i]]++;
            for(auto &[key,value] : mp)
            {
                cnt += value > 1;
            }
            
            return cnt;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]) == mp.end())
            {
                int x = nums[i] - k , y = nums[i] + k;
                if(mp.find(x) != mp.end()) cnt++;
                if(x != y and mp.find(y) != mp.end()) cnt++;
                
                mp[nums[i]] = 1;
            }
        }
        
        return cnt;   
    }
};