class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<size(matrix);i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(auto &v : matrix) reverse(v.begin(),v.end());
        
        // return matrix;
    }
};

// 1 4 7
// 2 5 8
// 3 6 9