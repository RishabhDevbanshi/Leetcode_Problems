class Solution {
    
    
    
    public int orangesRotting(int[][] grid) {
        int n = grid.length,m= grid[0].length;
        
        int time=-1;
        Queue<int []>qu = new LinkedList<>();
        
        for(int i=0;i<n;i++){
            for(int j= 0 ;j<m;j++){
                if(grid[i][j]==2) qu.offer(new int []{i,j});
            }
        }
        
        while(!qu.isEmpty()){
            int size = qu.size();
            
            for(int k=0;k<size;k++){
                var top = qu.poll();
                int i=top[0],j=top[1];
            
                if(isValid(i+1,j,n,m) && grid[i+1][j]==1){
                    qu.add(new int[]{i+1,j});
                    grid[i+1][j]=2;
                }
                
                if(isValid(i-1,j,n,m) && grid[i-1][j]==1){
                    qu.add(new int[]{i-1,j});
                    grid[i-1][j]=2;
                }
                
                if(isValid(i,j+1,n,m) && grid[i][j+1]==1){
                    qu.add(new int[]{i,j+1});
                    grid[i][j+1]=2;
                }
                
                if(isValid(i,j-1,n,m) && grid[i][j-1]==1){
                    qu.add(new int[]{i,j-1});
                    grid[i][j-1]=2;
                }
                
            }
            time++;
        }
        
        for(int i=0;i<n;i++){
            for(int j= 0 ;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        
        if(time==-1) return 0;
        return time;
    }
    
    private boolean isValid(int i,int j,int n,int m){
       return !(i<0 || i>=n || j<0 || j>=m);
    }
}