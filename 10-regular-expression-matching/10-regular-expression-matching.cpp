class Solution {
public:
    bool isMatch(string a, string p) {
        
        vector<vector<int>> dp(size(a)+1,vector<int>(size(p)+1,-1));
        
        function<bool(int,int)> recur = [&](int i,int j)->int{
            
            if(j == size(p))
                return i == size(a);
            
            int &ans = dp[i][j];
            
            if(ans != -1)
                return ans;
            
            if(p[j+1] == '*')
            {
                return ans = recur(i,j+2) or (i<size(a) and (a[i] == p[j] || p[j] == '.'))
                    and recur(i+1,j);
            }
            
            if(i<size(a) and (a[i] == p[j] or p[j] == '.'))
                return ans = recur(i+1,j+1);
            
            return ans = false;
        };
        
        return recur(0,0);
    }
};