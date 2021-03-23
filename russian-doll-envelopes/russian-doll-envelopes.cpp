class Solution {
public:
    static bool myCompare(vector<int> arr1,vector<int> arr2)
    {
        if(arr1[0] == arr2[0]) return arr1[1] > arr2[1];
        return arr1[0] < arr2[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        int *dp = new int[n]();
        sort(envelopes.begin(),envelopes.end(),myCompare);
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<2;j++) cout<<envelopes[i][j]<<" ";
        //     cout<<"\n";
        // }
        
        int ans = 1;
        dp[0] = 1;
        
        for(int i=1;i<n;i++)
        {
            int mx = 0;
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][1] > envelopes[j][1]) mx = max(mx,dp[j]);
            }
            dp[i] = mx + 1;
            cout<<dp[i]<<" ";
            ans = max(ans,dp[i]);
        }
        
        delete[] dp;
        
        return ans;
    }
};