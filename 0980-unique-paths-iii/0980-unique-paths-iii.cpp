#define vvi vector<vector<int>>

int rowArr[] = {1,-1,0,0};
int colArr[] = {0,0,1,-1};

class Solution {
    int cnt = 0;
    
    bool isValid(vvi &grid,int row,int col)
    {
        if(row<0 || col<0 || 
           row>=grid.size() || col>=grid[0].size()
           || grid[row][col] == -1 || grid[row][col] == 1)
            return false;
        return true;
    }
    
    void dfs(vvi &grid,int row,int col,int sq,int total)
    {
        if(!isValid(grid,row,col)) return;
        // cout<<row<<" "<<col<<"\n";
        if(grid[row][col] == 2)
        {
            // cout<<sq<<" ";
            cnt+= (sq == total);
            return;
        }
        
        grid[row][col] = -1;
        for(int i=0;i<4;i++) 
            dfs(grid,row+rowArr[i],col+colArr[i],sq+1,total);
        grid[row][col] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        cnt=0;
        int total = 0;
        int x,y;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 0) total++;
                else if(grid[i][j] == 1) x=i,y=j;
            }
        }
        // cout<<x<<" "<<y;
        for(int i=0;i<4;i++) dfs(grid,x+rowArr[i],y+colArr[i],0,total);
        
        return cnt;
    }
};