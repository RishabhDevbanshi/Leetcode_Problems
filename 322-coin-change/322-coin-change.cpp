class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[size(coins)][amount+1];
        memset(dp,-1,sizeof dp);
        
        function<int(int,int)> fun = [&](int idx, int amt){
            if(amt == 0)
                return 0;
            if(idx == size(coins))
                return 1000000;
            
            if(dp[idx][amt] != -1)
                return dp[idx][amt];
            
            if(coins[idx] > amt)
                return dp[idx][amt] = fun(idx+1,amt);
            
            int op1 = fun(idx+1,amt);
            int op2 = 1 + fun(idx,amt - coins[idx]);
            
            return dp[idx][amt] = min(op1,op2);
        };
        
        int val = fun(0,amount);
        
        return val == 1000000 ? -1 : val;;
    }
};