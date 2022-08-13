class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        auto dead_end = [&](string &str,int i){
          int tot=0;
            for(int x=i;x<size(str);x++) 
                tot += int(str[x]);
            return tot;
        };
        
        vector<vector<int>> dp(size(s1)+1,vector<int>(size(s2)+1,-1));
        
        function<int(int,int)> dfs = [&](int i,int j){
            if(i == size(s1) or j == size(s2))
                return i==size(s1) ? dead_end(s2,j) : dead_end(s1,i);
            
            if(dp[i][j] != -1)
                return dp[i][j];
            
            if(s1[i] == s2[j])
                return dp[i][j] = dfs(i+1,j+1);
            else
                return dp[i][j] = min(int(s1[i]) + dfs(i+1,j) , int(s2[j]) + dfs(i,j+1));
        };
        
        
        
        return dfs(0,0);
        
    }
};