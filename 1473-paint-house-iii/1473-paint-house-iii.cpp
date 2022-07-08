class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        int dp[m+1][n+1][target+1];
        memset(dp,-1,sizeof dp);
        
        
        function<int(int,int,int)> dfs = [&](int idx,int prevCol,int nbr)->int{
            if(idx == size(houses))
                return nbr == 0 ? 0 : INT_MAX;
            
            if(nbr < 0)
                return INT_MAX;
            
            if(nbr == 0)
            {
                if(houses[idx] and prevCol != houses[idx])
                    return INT_MAX;
                if(houses[idx] and prevCol == houses[idx])
                    return dfs(idx+1,prevCol,nbr);
                
                int val = dfs(idx+1,prevCol,nbr);
                
                if(val == INT_MAX)
                    return val;
                
                return val + cost[idx][prevCol-1];
            }
            
            if(houses[idx])
                return dfs(idx+1,houses[idx],prevCol == houses[idx] ? nbr : nbr-1);
            
            if(dp[idx][prevCol][nbr] != -1)
                return dp[idx][prevCol][nbr];
            
            int mini = INT_MAX;
            
            for(int i=1;i<=size(cost[idx]);i++)
            {
                int val;
                if(i == prevCol)
                    val = dfs(idx+1,i,nbr);
                else 
                    val = dfs(idx+1,i,nbr-1);
                if(val != INT_MAX)
                    val += cost[idx][i-1];
                
                mini = min(mini,val);
            }
            
            return dp[idx][prevCol][nbr] = mini;
        };
        
        int ans = dfs(0,0,target);
        
        return ans == INT_MAX ? -1 : ans;
    }
};