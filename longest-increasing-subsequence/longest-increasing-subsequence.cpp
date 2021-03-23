class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int *dp = new int[n]();
        dp[0] = 1;
        int ans = 1;
        for(int i=1;i<n;i++)
        {
            int mx = 0;
            for(int j=0;j<i;j++)
            {
                if(arr[j] < arr[i])
                {
                    mx = max(mx,dp[j]);
                }
            }
            dp[i] = mx  + 1;
            ans = max(ans,dp[i]);
        }
        
        delete[] dp;
        return ans;
    }
};