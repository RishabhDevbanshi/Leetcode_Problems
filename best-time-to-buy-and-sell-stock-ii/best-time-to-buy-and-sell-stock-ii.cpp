class Solution {
    int f(vector<int> &arr,int idx,int buy,int profit)
    {
        if(idx == arr.size()-1) 
        {
            if(buy == -1) return profit;
            return arr[idx] < buy ? profit : profit + arr[idx] - buy;
        }
        
        int op1 = f(arr,idx+1,buy,profit);
        int op2 = 0;
        if(buy==-1)
        {
            op2 = f(arr,idx+1,arr[idx],profit);
        }
        else if(buy < arr[idx])
        {
            op2 = f(arr,idx+1,-1,profit + arr[idx] - buy);
        }
        
        return max(op1,op2);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,0);
        int mx = prices[n-1];
        
        int lp = dp.back();
        
        for(int i=n-2;i>=0;i--)
        {
            int inc = mx < prices[i] ? 0 : mx - prices[i];
            if(inc < lp)
            {
                mx = prices[i];
                dp[i] = 0;
                lp = 0;
            }
            else
            {
                dp[i] = inc;
                dp[i+1] = 0;
                lp = inc;
                mx = max(mx,prices[i]);
            }
        }
        
        int res = 0;
        for(auto &val : dp) res += val;
        
        
        return res;
    }
};