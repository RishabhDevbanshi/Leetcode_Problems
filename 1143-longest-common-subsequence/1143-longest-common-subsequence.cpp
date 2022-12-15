class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(size(text1)+1,vector<int>(size(text2)+1,-1));
        
        function<int(int,int)> memo = [&](int i,int j){
            if(i == size(text1) || j == size(text2))
                return 0;
            if(dp[i][j] != -1)
                return dp[i][j];
            int ans = max(memo(i,j+1),memo(i+1,j));
            if(text1[i] == text2[j])
                ans = max(ans,1 + memo(i+1,j+1));
            return dp[i][j] = ans;
        };     
        
        return memo(0,0);
    }
};