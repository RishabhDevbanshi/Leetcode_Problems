class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       
        int n = size(nums);
        
        if(n < 3) return 0;
        
        vector<int> dp(n+1,0);
        dp[2] = nums[2]-nums[1] == nums[1]-nums[0];
        int res = dp[2];
        
        for(int i=3;i<n;i++)
        {
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2])
                dp[i] = dp[i-1] + 1;
            
            res += dp[i];
        }
        
        return res;
    }
};