class Solution {
    typedef long long ll;
    ll dp[2][1001][101];
    
    ll recur(vector<int> &arr,int k,int n,int idx=0,bool ok=false)
    {
        if(idx>=n || k==0)
            return 0;
            
        if(dp[ok][idx][k] != -1)
            return dp[ok][idx][k];
        
        ll sum = recur(arr,k,n,idx+1,ok);
        
        if(ok)
        {
            sum = max(sum , recur(arr,k-1,n,idx+1,false) + arr[idx]);
        }
        else
        {
            sum = max(sum , recur(arr,k,n,idx+1,true) - arr[idx]);
        }
        
        return dp[ok][idx][k] = sum;
        
    }
public:
    int maxProfit(int k, vector<int>& prices) {
         memset(dp,-1,sizeof dp);
        
        return recur(prices,k,size(prices),0,false);
    }
};