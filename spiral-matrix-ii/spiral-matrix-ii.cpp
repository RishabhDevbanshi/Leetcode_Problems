class Solution {
public:
    vector<vector<int>> generateMatrix(int A) {
        vector<vector<int>> arr(A,vector<int>(A));
        int num=1, top=0, left=0, right=A-1, bottom=A-1;
        while(num <= A*A)
        {
            for(int i=left;i<=right;i++) arr[top][i] = num++;
            top++;
            for(int i=top;i<=bottom;i++) arr[i][right] = num++;
            right--;
            for(int i=right;i>=left;i--) arr[bottom][i] = num++;
            bottom--;
            for(int i=bottom;i>=top;i--) arr[i][left] = num++;
            left++;
        }

        return arr;
    }
};