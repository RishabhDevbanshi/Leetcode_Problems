class Solution {
public:
    int lb(int start,int end,int target,vector<int> &arr)
    {
        int ans = 0;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] > target) 
            {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return ans;
    }
    
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp;
        dp.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(arr[i] > dp.back()) dp.push_back(arr[i]);
            else
            {
                int idx = lb(0,dp.size(),arr[i],dp);
                dp[idx] = arr[i];
            }
        }
        
        int ans = dp.size();
        dp.clear();
        return ans;
    }
};