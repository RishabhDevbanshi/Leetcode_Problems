class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i = 0 , j = size(matrix[0])-1;
        
        while(i>=0 and j>=0 and i<size(matrix) and j<size(matrix[0]))
        {
            // cout<<matrix[i][j]<<" "; 
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) i++;
            else j--;
            
        }
        
        return false;
    }
};