class Solution {
    int recur(string &word1,string &word2,int m,int n,vector<vector<int>> &dp)
    {
        if(m == 0)
            return n;
        if(n == 0)
            return m;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(word1[m-1] == word2[n-1])
            return dp[m][n] = recur(word1,word2,m-1,n-1,dp);
        
        int ins = 1 + recur(word1,word2,m,n-1,dp);
        int del = 1 + recur(word1,word2,m-1,n,dp);
        int rep = 1 + recur(word1,word2,m-1,n-1,dp);
        
        return dp[m][n] = min({ins,del,rep});
    }
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(size(word1)+1,vector<int>(size(word2)+1,-1));
        
        return recur(word1,word2,size(word1),size(word2),dp);
    
    }
};