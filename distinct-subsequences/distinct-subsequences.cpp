class Solution {
    int recur(string &a, string &b, int x, int y, vector<vector<int>> &dp)
    {
        if (y == b.size()) return 1;
        if (x == a.size()) return 0;

        if (dp[x][y] != -1)
            return dp[x][y];

        if (a[x] != b[y])
            return dp[x][y] = recur(a, b, x + 1,  y, dp);
        else return dp[x][y] = recur(a, b, x + 1, y + 1, dp) + recur(a, b, x + 1, y, dp);
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return recur(s,t,0,0,dp);
    }
};