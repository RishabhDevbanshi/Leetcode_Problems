class Solution {
    void recur(vector<int> &nums,int idx,int *dp)
    {
        if(idx < 0) return;
        
        recur(nums,idx-1,dp);
        
        int len = 0;
        
        for(int i=0;i<idx;i++)
        {
            if(nums[i] < nums[idx]) len = max(len,dp[i]);
        }
        
        dp[idx] = 1 + len;
    }
    
    void rucer(vector<int> &nums,int idx,int *dp)
    {
        if(idx == nums.size()) return;
        
        rucer(nums,idx+1,dp);
        
        int len = 0;
        
        for(int i=idx+1;i<nums.size();i++)
        {
            if(nums[idx] > nums[i]) len = max(len,dp[i]);
        }
        
        dp[idx] = 1 + len;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        int dp[n] , pd[n];
        
        recur(nums,n-1,dp);
        rucer(nums,0,pd);
        
        int len = 0;
        
        for(int i=0;i<nums.size();i++) 
            if(dp[i]>1 and pd[i]>1)
                len = max(len , dp[i] + pd[i] - 1);
        
        return nums.size() - len ;
    }
};