class Solution {
    vector<int> dp;
    
    bool recur(int n)
    {
        if(n == 0)
            return false;
        
        if(dp[n] != -1)
            return dp[n];
        
        bool ans = false;
        
        for(int i=1;i*i<=n;i++)
        {
            //f there exists a possibility where other player loosea then current won !
            ans = ans || !recur(n - (i*i));
        }
        
        return dp[n] = ans;
    }
public:
    bool winnerSquareGame(int n) {
        dp.resize(n+1,-1);
        return recur(n);
    }
};