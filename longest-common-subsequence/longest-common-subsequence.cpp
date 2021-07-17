class Solution {
//     int recur(string s1,string s2,int n1,int n2,vector<vector<int>> &dp)
//     {
//         if(n1 == 0 || n2 == 0)
//             return 0;
        
//         if(dp[n1][n2] != -1)
//             return dp[n1][n2];
        
//         if(s1[n1 - 1] != s2[n2 - 1])
//             return dp[n1][n2] = max(recur(s1,s2,n1-1,n2,dp),recur(s1,s2,n1,n2-1,dp));
        
//         else return dp[n1][n2] = 1 + recur(s1,s2,n1-1,n2-1,dp);
//     }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        int x = text1.size() , y = text2.size();
        
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        return dp[x][y];
    }
};