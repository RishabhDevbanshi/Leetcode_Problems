class Solution {
public:
    int countSubstrings(string str) {
        int n = str.size();
        int count = 0;
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        
        for(int gap = 0; gap < n; gap++)
        {
            for(int i=0,j=gap; j<n; i++,j++)
            {
                if(gap == 0) dp[i][j] = true;
                else if(gap == 1) dp[i][j] = str[i] == str[j];
                else
                {
                    if(str[i] == str[j] and dp[i+1][j-1]) dp[i][j] =true;
                }
                
                if(dp[i][j]) count++;
            }
        }
        
        dp.clear();
        return count;
    }
};