class Solution {
    
    int bs(vector<int> &days,int idx,int curr)
    {
        int ans = size(days);
        int start = curr , end = size(days)-1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(days[mid] == idx) return mid;
            else if(days[mid] > idx) ans = mid , end = mid-1;
            else start = mid+1;
        }
        
        return ans;
    }
    
    int recur(vector<int> &days,vector<int> &costs,int idx,int *dp)
    {
        if(idx >= size(days)) return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        //case 1 : 1 day pass
        int new_idx = bs(days,days[idx] + 1,idx+1);
        int op1 = costs[0] + recur(days,costs,new_idx,dp);
        
        //case 2 : 7-days pass
        new_idx = bs(days,days[idx]+7,idx+1);
        int op2 = costs[1] + recur(days,costs,new_idx,dp);
        
        //case 3 : 30-days pass
        new_idx = bs(days,days[idx]+30,idx+1);
        int op3 = costs[2] + recur(days,costs,new_idx,dp);
        
        return dp[idx] = min({op1,op2,op3});
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int dp[400];
        memset(dp,-1,sizeof(dp));
        
        return recur(days,costs,0,dp);
    
    }
};