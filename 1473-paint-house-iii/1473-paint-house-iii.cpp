class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        unordered_map<string,long> mp;
        long dp[m+1][n+1][target+1];
        memset(dp,-1,sizeof dp);
        
        
        function<long(int,int,int)> dfs = [&](int idx,int prevCol,int nbr)->long{
            if(idx == size(houses))
                return nbr == 0 ? 0 : 1e17;
            
            if(nbr < 0)
                return 1e17;
            
            if(nbr == 0)
            {
                if(houses[idx] and prevCol != houses[idx])
                    return 1e17;
                if(houses[idx] and prevCol == houses[idx])
                    return dfs(idx+1,prevCol,nbr);
                
                long val = dfs(idx+1,prevCol,nbr);
                
                if(val == 1e17)
                    return val;
                
                return val + cost[idx][prevCol-1];
            }
            
            if(houses[idx])
                return dfs(idx+1,houses[idx],prevCol == houses[idx] ? nbr : nbr-1);
            
            if(dp[idx][prevCol][nbr] != -1)
                return dp[idx][prevCol][nbr];
            
            long mini = 1e17;
            
            for(int i=1;i<=size(cost[idx]);i++)
            {
                long val;
                if(i == prevCol)
                    val = dfs(idx+1,i,nbr);
                else 
                    val = dfs(idx+1,i,nbr-1);
                if(val != 1e17)
                    val += cost[idx][i-1];
                
                mini = min(mini,val);
            }
            
            return dp[idx][prevCol][nbr] = mini;
        };
        
        long ans = dfs(0,0,target);
        
        return ans == 1e17 ? -1 : ans;
    }
};