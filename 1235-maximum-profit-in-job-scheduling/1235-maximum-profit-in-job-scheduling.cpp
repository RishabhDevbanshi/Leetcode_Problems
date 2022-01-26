class Solution {
    struct interval{
        int start , end , profit;
    };
    
    vector<interval> nums;
    vector<int> dp;
    
    int findNext(int idx)
    {
        int start = idx , end = size(nums)-1;
        int res = -1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(nums[mid].start >= nums[idx].end)
                res = mid , end = mid-1;
            else 
                start = mid+1;
        }
        
        return res;
    }
    
    int maxProfit(int idx = 0)
    {
        if(idx >= size(nums))
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int next = findNext(idx);
        
        int include = nums[idx].profit + (next == -1 ? 0 : maxProfit(next));
        
        int exclude = maxProfit(idx + 1);
        
        return dp[idx] = max(include,exclude);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = size(profit);
        
        nums.resize(n);
        dp.resize(n+1,-1);
        
        for(int i=0;i<n;i++)
        {
            nums[i].start = startTime[i];
            nums[i].end = endTime[i];
            nums[i].profit = profit[i];
        }
        
        sort(nums.begin(),nums.end(),[&](interval &a,interval &b){
            return a.start < b.start;
        });
        
        
        
        return maxProfit();
    }
};