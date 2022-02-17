class Solution {
    
    vector<vector<int>> dp;
    
    int recur(vector<int> &nums,int idx,int rem)
    {
        if(idx == size(nums))
        {
            return rem == 0 ? 0 : INT_MIN;
        }
        
        if(dp[idx][rem] != -1)
            return dp[idx][rem];
        
        int op1 = recur(nums,idx+1,rem);
        int op2 = recur(nums,idx+1,(rem + nums[idx])%3) + nums[idx];
        
        return dp[idx][rem] = max(op1,op2);
    }
    
public:
    int maxSumDivThree(vector<int>& nums) {
        
        dp.resize(size(nums),vector<int>(3,-1));
        
        return recur(nums,0,0);
        
    }
};