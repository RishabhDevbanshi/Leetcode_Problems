class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int op1 = (j+1 < n) ? matrix[i+1][j+1] : 1e5;
                int op2 = matrix[i+1][j];
                int op3 = (j-1 >= 0) ? matrix[i+1][j-1] : 1e5;
                // cout<<op1<<" "<<op2<<" "<<op3<<"\n";
                matrix[i][j] += min({op1,op2,op3});
            }
        }
        
        int res = 1e5;
        
        // for(auto &v : matrix)
        // {
        //     for(auto &val : v) cout<<val<<" ";
        //     cout<<"\n";
        // }
        
        for(auto &ele : matrix[0]) res = min(res,ele);
        
        return res;
    }
};