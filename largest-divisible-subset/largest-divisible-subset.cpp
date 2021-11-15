class Solution {
    int index = 0 , mx = 0;
    void recur(vector<int> &nums,int idx,int *dp)
    {
        if(idx == nums.size()) return;
        
        recur(nums,idx+1,dp);
        
        int len = 0;
        for(int i=idx+1;i<nums.size();i++)
        {
            if(nums[i]%nums[idx] == 0) len = max(len,dp[i]);
        }
        
        dp[idx] = 1 + len;
        if(dp[idx] > mx) mx = dp[idx] , index = idx;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int dp[nums.size()];
        index = mx = 0;
        sort(nums.begin(),nums.end());
        recur(nums,0,dp);
        vector<int> res;
        int val = nums[index];
        int i=index , cnt = 0;
        while(i<nums.size() and mx > 0)
        {
            if(nums[i]%val == 0 and dp[i] == mx)
            {
                res.push_back(nums[i]);
                val = res.back();
                --mx;
            }
            ++i;
        }
        
        return res;
    }
};