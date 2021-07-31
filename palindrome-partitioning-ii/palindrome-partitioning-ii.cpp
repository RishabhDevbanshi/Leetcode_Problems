class Solution {
    bool isPal(string str,int i,int j)
    {
        while(i<=j)
        {
            if(str[i] != str[j]) return false;
            i++ , j--;
        }
        return true;
    }
    
    int recur(string str,int i,int j,vector<vector<int>> &dp)
    {
        if(i >= j) return dp[i][j] = 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(isPal(str,i,j)) return dp[i][j] = 0;
        
        int res = INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int left = dp[i][k] != -1 ? dp[i][k] : recur(str,i,k,dp);
            int right = dp[k+1][j] != -1 ? dp[k+1][j] : recur(str,k+1,j,dp);
            
            int tmp = 1 + left + right;
            
            res = min(res,tmp);
        }
        
        return dp[i][j] = res;
    }
public:
    int minCut(string s) {
         const int N = s.size();
            if(N<=1) return 0;
            int i,j;
            bool isPalin[N][N];
            fill_n(&isPalin[0][0], N*N, false);
            int minCuts[N+1];
            for(i=0; i<=N; ++i) minCuts[i] = i-1;
            
            for(j=1; j<N; ++j)
            {
                for(i=j; i>=0; --i)
                {
                    if( (s[i] == s[j]) && ( ( j-i < 2 ) || isPalin[i+1][j-1] ) )
                    {
                        isPalin[i][j] = true;
                        minCuts[j+1] = min(minCuts[j+1], 1 + minCuts[i]);    
                    }
                }
            }
            return minCuts[N];
    }
};