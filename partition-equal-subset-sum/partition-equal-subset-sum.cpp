class Solution {
    int dp[204][10004];
    bool recur(vector<int> &nums,int n,int sum)
    {
        if(sum == 0) return true;
        if(n < 0) return false;
        
        if(dp[n][sum] != -1) return dp[n][sum]; 
        
        if(nums[n] > sum) return dp[n][sum] = recur(nums,n-1,sum);
        
        return dp[n][sum] = recur(nums,n-1,sum) || recur(nums,n-1,sum - nums[n]);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int ele : nums) sum += ele;
        
        if(sum&1) return false;
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum/2;j++) dp[i][j] = -1;
        }
        
        return recur(nums,n-1,sum/2);
    }
};