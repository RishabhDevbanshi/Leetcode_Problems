class Solution {
    public boolean rec(int [][] arr,int ele,int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j >= m) return false;
        
        if(arr[i][j] == ele) return true;
        
        else if(arr[i][j] < ele) return rec(arr,ele,i+1,j,n,m);
        
        else return rec(arr,ele,i,j-1,n,m);
    }
    
    public boolean searchMatrix(int[][] matrix, int target) {
        
        int n = matrix.length , m = matrix[0].length;
        
        return rec(matrix,target,0,m-1,n,m);
        
    }
}