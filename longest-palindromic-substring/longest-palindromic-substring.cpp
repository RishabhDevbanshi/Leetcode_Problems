class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size();
       vector<vector<bool>> dp(n,vector<bool> (n,false));
       pair<int,int> idx;

       for(int gap = 0;gap<n;gap++)
       {
           for(int i=0,j=gap;j<n;j++,i++)
           {
               if(gap == 0) dp[i][j] = true;
               else if(gap == 1) dp[i][j] = str[i] == str[j];
               else dp[i][j] = (str[i] == str[j] and dp[i+1][j-1]);

               if(dp[i][j]) idx = {i,j};
           }
       }
       
       string ans;
        dp.clear();
       for(int i = idx.first; i<= idx.second; i++) ans += str[i];
        return ans;
    }
};