class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        int sum = 0;
        int len = 0;
        
        int i=0;
        
        for(auto &val : nums)
        {
            sum += val == 1 ? 1 : -1;
            
            if(mp.count(sum))
                len = max(len,i - mp[sum]);
            else
                mp[sum] = i;
            
            if(sum == 0)
                len = max(len,i+1);
            i++;
        }
        
        return len;
    }
};