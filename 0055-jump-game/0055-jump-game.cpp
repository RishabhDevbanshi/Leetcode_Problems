class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        vector<int> dp(size(nums)+1,-1);
        
        function<int(int)> dfs = [&](int idx)->int{
            if(idx >= size(nums))
                return false;
            if(idx == size(nums)-1)
                return true;
            if(dp[idx] != -1)
                return dp[idx];
            for(int i=1;i<=nums[idx];i++)
            {
                if(dfs(idx+i))
                    return dp[idx] = true;
            }
            return dp[idx] = false;
        };
        
        
        return dfs(0);
    }
};