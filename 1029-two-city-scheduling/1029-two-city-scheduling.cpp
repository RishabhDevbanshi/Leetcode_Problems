class Solution {
   
    int dp[100][100];
   
    int recur(vector<vector<int>> &costs,int idx,int f,int s)
    {
        if(idx == size(costs))
            return 0;
       
        if(dp[f][s] != -1)
            return dp[f][s];
       
        if(f == size(costs)>>1)
            return dp[f][s] = costs[idx][1] + recur(costs,idx+1,f,s+1);
        else if(s == size(costs)>>1)
        {
            return dp[f][s] = costs[idx][0] + recur(costs,idx+1,f+1,s);
        }
        else
        {
            int a = costs[idx][0] + recur(costs,idx+1,f+1,s);
            int b = costs[idx][1] + recur(costs,idx+1,f,s+1);
           
            return dp[f][s] = min(a,b);
        }
       
       
    }
   
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof dp);
        return recur(costs,0,0,0);
       
    }
};