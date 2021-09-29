class Solution {
    int recur(vector<vector<int>> &dp,string str, int start,int end)
    {
        if(start >= end) return 1;
        if(dp[start][end] != -1) return dp[start][end];
        
        return dp[start][end] = str[start] == str[end] ? recur(dp,str,start+1,end-1) : 0;
    }
public:
    int countSubstrings(string str) {
        int n = str.size(), cnt = 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                cnt += recur(dp,str,i,j);
            }
        }
        
        
        return cnt;
    }
};