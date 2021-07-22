class Solution {
    public int minPathSum(int[][] grid) {
        
        int n = grid.length , m = grid[0].length;
        
        for(int i=n-2;i>=0;i--)
            grid[i][m-1] += grid[i+1][m-1];
        for(int i=m-2;i>=0;i--)
            grid[n-1][i] += grid[n-1][i+1];
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                grid[i][j] += Integer.min(grid[i+1][j],grid[i][j+1]);
                // System.out.print(grid[i][j] + " ");
            }
            // System.out.println();
        }
        
        return grid[0][0];
    }
}