class Solution {
    
    // map<vector<int>,int> mp;
    // unordered_map<pair<int,int>,int> mp;
    int dp[1003][1003];
    
    int recur(vector<int> &nums,vector<int> &multipliers,int idx,int start,int end)
    {
        if(start > end) return 0;
        if(idx == size(multipliers)) return 0;
        
        if(dp[idx][start] != -1)
            return dp[idx][start];
        
        // if(idx == size(multipliers)-1) return multipliers[idx] * max()
        
        int op1 = nums[start]*multipliers[idx] + recur(nums,multipliers,idx+1,start+1,end);
        int op2 = nums[end]*multipliers[idx] + recur(nums,multipliers,idx+1,start,end-1);
        
        return dp[idx][start] = max(op1,op2);
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // mp.clear();
        memset(dp,-1,sizeof dp);
        return recur(nums,multipliers,0,0,size(nums)-1);
    }
};