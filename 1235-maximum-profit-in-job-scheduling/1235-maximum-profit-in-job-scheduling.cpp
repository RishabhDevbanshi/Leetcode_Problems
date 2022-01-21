class Solution {
    struct interval
    {
        int s;
        int e;
        int p;
    };
    
    vector<interval> nums;
    vector<int> dp;
    
    int findNext(int idx)
    {
        int start = idx + 1 , end = size(nums)-1;
        int ans = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid].s >= nums[idx].e)
                ans = mid , end = mid-1;
            else 
                start = mid+1;
        }
        
        return ans;
    }
    
    int maxProfit(int idx=0)
    {
        if(idx >= size(nums))
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int next = findNext(idx);
        int include = nums[idx].p + (next == -1 ? 0 : maxProfit(next));
        
        int exclude = maxProfit(idx+1);
        
        
        return dp[idx] = max(include , exclude);
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = size(startTime);
        nums.resize(n);
        dp.resize(n+1,-1);
        
        for(int i=0;i<size(startTime);i++)
        {
            nums[i].s = startTime[i] , nums[i].e = endTime[i] , nums[i].p = profit[i];
        }
        
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){
            return a.s < b.s;
        });
        
        return maxProfit();
    }
};