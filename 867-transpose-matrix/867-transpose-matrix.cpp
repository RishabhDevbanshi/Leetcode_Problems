class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>> trans(size(matrix[0]) , vector<int>(size(matrix)));
        
        for(int i=0;i<size(matrix);i++)
        {
            for(int j=0;j<size(matrix[0]);j++)
                trans[j][i] = matrix[i][j];
        }
        
        
        return trans;
    }
};