class Solution {
public:
    int longestValidParentheses(string s) {
        if(size(s) == 0)
            return 0;
        
        // int ans = 0;
        
        auto fun = [&](string s,bool ok){
            vector<vector<int>> dp(size(s)+1,vector<int>(2));
        
            int res = 0;

            for(int i=1;i<=size(s);i++)
            {
                dp[i][0] = dp[i-1][0] , dp[i][1] = dp[i-1][1];
                if(s[i-1] == ')')
                    dp[i][1]++;
                else
                    dp[i][0]++;

                if(ok)
                {
                    if(dp[i][0] < dp[i][1])
                        dp[i][0] = 0 , dp[i][1] = 0;
                }
                else
                {
                    if(dp[i][0] > dp[i][1])
                        dp[i][0] = 0 , dp[i][1] = 0;
                }

                if(dp[i][0] == dp[i][1])
                    res = max(res,2 * dp[i][0]);
            }
            
            return res;
        };
        
        int op1 = fun(s, true);
        
        reverse(s.begin(),s.end());
        
        int op2 = fun(s , false);
        
        return max(op1,op2);
    }
};