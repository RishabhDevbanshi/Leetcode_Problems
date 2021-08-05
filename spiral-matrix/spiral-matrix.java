class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int n = matrix.length , m = matrix[0].length;
        List arr = new ArrayList();
        int top=0, left=0, right=m-1, bottom=n-1, k=0;
        while(arr.size() < n*m )
        {
            if(arr.size() == n*m) break;
            for(int i=left;i<=right;i++)  {arr.add(matrix[top][i]); k++; if(arr.size() == n*m) break;}
            top++;
            if(arr.size() == n*m) break;
            for(int i=top;i<=bottom;i++) {arr.add(matrix[i][right]); k++; if(arr.size() == n*m) break;}
            right--;
            if(arr.size() == n*m) break;
            for(int i=right;i>=left;i--) {arr.add(matrix[bottom][i]); k++; if(arr.size() == n*m) break;}
            bottom--;
            if(arr.size() == n*m) break;
            for(int i=bottom;i>=top;i--) {arr.add(matrix[i][left]); k++; if(arr.size() == n*m) break;}
            left++;
            if(arr.size() == n*m) break;
        }
        
        return arr;   
    }
}