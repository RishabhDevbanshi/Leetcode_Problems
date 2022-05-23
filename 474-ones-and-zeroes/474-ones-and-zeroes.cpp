class Solution {
public:
    int findMaxForm(vector<string>& str, int m, int n) {
        
        
        int dp[m+1][n+1][size(str)+1];
        memset(dp,-1,sizeof dp);
        
        function<int(int,int,int)> fun = [&](int m,int n,int idx){
            if(idx == size(str) || (m == 0 and n == 0))
                return 0;
            
            if(dp[m][n][idx] != -1)
                return dp[m][n][idx];
            
            int co = 0 , cz = 0;
            for(auto &ch : str[idx])
                ch == '0' ? cz++ : co++;
            
            if(cz > m || co > n)
                return dp[m][n][idx] = fun(m,n,idx+1);
            else
                return dp[m][n][idx] = max(fun(m,n,idx+1),1 + fun(m-cz,n-co,idx+1));
        };
        
        
        return fun(m,n,0);
    }
};