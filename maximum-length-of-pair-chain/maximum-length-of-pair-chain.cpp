class Solution {
    void recur(vector<vector<int>> &pairs,int idx,int *dp)
    {
        if(idx == pairs.size()) return;
        
        recur(pairs,idx+1,dp);
        
        int len = 0;
        
        for(int i=idx+1;i<pairs.size();i++)
        {
            if(pairs[idx][1] < pairs[i][0]) 
                len = max(len,dp[i]);
        }
        
        dp[idx] = 1 + len;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        
        sort(pairs.begin(),pairs.end(),[&](vector<int> &a,vector<int> &b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        recur(pairs,0,dp);
        
        int ans = 0;
        for(int i=0;i<n;i++) ans = max(ans,dp[i]);
        
        return ans;
    }
};