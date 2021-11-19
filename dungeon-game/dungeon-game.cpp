class Solution {
  // 6   4   1
  // 5   10  4
  // 0   0   5
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size() , m = dungeon[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        
        dp[n-1][m-1] = dungeon[n-1][m-1] < 0 ? abs(dungeon[n-1][m-1]) : 0;
        
        for(int i=n-2;i>=0;i--) 
        {
            // int val = dungeon[i][0] < 0 ? abs(dungeon[i][0]) : 0;
            dp[i][m-1] = dp[i+1][m-1] - dungeon[i][m-1];
            if(dp[i][m-1] < 0) dp[i][m-1] = 0;
        }
        
        for(int i=m-2;i>=0;i--)
        {
            dp[n-1][i] = dp[n-1][i+1] - dungeon[n-1][i];
            if(dp[n-1][i] < 0) dp[n-1][i] = 0;
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                dp[i][j] = min(dp[i][j+1] , dp[i+1][j]) - dungeon[i][j];
                if(dp[i][j] < 0) dp[i][j] = 0;
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++) cout<<dp[i][j]<<"\t";
        //     cout<<endl;
        // }
        
        return 1 + dp[0][0];
    }
};