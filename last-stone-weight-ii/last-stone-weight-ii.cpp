class Solution {
public:
    int lastStoneWeightII(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int ele : arr) sum += ele;
        int val = sum/2;
        bool dp[n+1][val+1];
        dp[0][0] = true;
        for(int i=1;i<=val;i++) dp[0][i] = false;
        for(int i=1;i<=n;i++) dp[i][0] = true;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=val;j++)
            {
                if(arr[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                
                // cout<<dp[i][j]<<" ";
            }
            // cout<<"\n";
        }
        
        int ans = sum;
        
        for(int i=val;i>=0;i--)
        {
            if(dp[n][i]) ans = min(ans,sum - 2*i);
        }
        
        return ans;
    }
};