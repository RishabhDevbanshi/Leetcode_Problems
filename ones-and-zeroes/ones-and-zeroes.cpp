class Solution {
    int dp[105][105][605];
    
    int recur(vector<string> &strs,int m,int n,int i)
    {
        if(i == strs.size() or (m==0 and n==0)) return 0;
        
        if(dp[m][n][i] != -1) 
            return dp[m][n][i];
        
        int zero = 0 , one = 0;
        for(auto ele : strs[i]) 
        {
            zero += ele == '0';
            one += ele == '1';
        }
        
        if(zero > m or one > n)
            return dp[m][n][i] = recur(strs,m,n,i+1);
        
        return dp[m][n][i] = max(recur(strs,m,n,i+1),1 + recur(strs,m-zero,n-one,i+1));
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<strs.size();k++) dp[i][j][k] = -1;
            }
        }
        
        return recur(strs,m,n,0);
    }
};