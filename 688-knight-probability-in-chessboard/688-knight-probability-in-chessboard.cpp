vector<pair<int,int>> dir = {
    {-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}
};

class Solution {
    
    double dp[105][105][105];
    
    bool isValid(int n,int i,int j)
    {
        return i>=0 and j>=0 and i<n and j<n;
    }
    
    double recur(int n,int k,int i,int j)
    {
        if(!isValid(n,i,j)) return 0;
        if(k == 0) return 1;
        
        if(dp[i][j][k] != (double)0)
            return dp[i][j][k];
        
        double prob = 0;
        
        for(auto &ele : dir)
        {
            prob += 0.125 * recur(n,k-1,i + ele.first , j + ele.second);
        }
        
        return dp[i][j][k] = prob;
    }
    
    
public:
    double knightProbability(int n, int k, int row, int column) {
        
        memset(dp,0,sizeof(dp));
        
        return recur(n,k,row,column);
    }
};