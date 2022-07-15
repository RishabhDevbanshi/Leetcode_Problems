class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k)
            return false;
        
        int req = sum/k;
        
        map<pair<int,pair<int,pair<int,int>>>,bool> mp;
        
        int vis = 0;
        
        function<bool(int ,int ,int)> dfs = [&](int i,int k,int curr){
            if(k == 1)
                return true;
            
            pair<int,pair<int,pair<int,int>>> key = {i,{k,{curr,vis}}};
            
            if(mp.find(key) != mp.end())
                return mp[key];
            
            if(curr == req)
            {
                return mp[key] = dfs(0,k-1,0);
            }
            
            for(int j=i;j<size(nums);j++)
            {
                int bit = (vis>>j)&1;
                if(bit || curr + nums[j] > req)
                    continue;
                
                // vis[j] = true;
                vis ^= (1<<j);
                bool ok = dfs(j+1,k,curr + nums[j]);
                if(ok)
                    return mp[key] = true;
                // vis[j] = false;
                vis ^= (1<<j);
            }
            
            
            return mp[key] = false;
        };
        
        return dfs(0,k,0);
    }
};