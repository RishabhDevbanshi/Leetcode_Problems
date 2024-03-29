class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k)
            return false;
        
        sort(nums.begin(),nums.end(),greater<int>());
        
        
        int req = sum/k;
        
        int vis = 0;
        
        function<bool(int ,int ,int)> dfs = [&](int i,int k,int curr){
            if(k == 1)
                return true;
            
            if(i >= size(nums))
                return false;
            
            if(curr == req)
            {
                return dfs(0,k-1,0);
            }
            
            for(int j=i;j<size(nums);j++)
            {
                int bit = (vis>>j)&1;
                if(bit || curr + nums[j] > req)
                    continue;
                
                vis ^= (1<<j);
                bool ok = dfs(j+1,k,curr + nums[j]);
                if(ok)
                    return true;
                vis ^= (1<<j);
            }
            
            
            return false;
        };
        
        return dfs(0,k,0);
    }
};