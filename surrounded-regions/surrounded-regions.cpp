// for 4 directions
int drow[4] = {1,0,-1,0};
int dcol[4] = {0,1,0,-1};

class Solution {
    //to check if a given idx is valid and value at that idx is 'O' or not
    bool isValid(vector<vector<char>> &board,int i,int j,int r,int c)
    {
        if(i>=0 and j>=0 and i<r and j<c and board[i][j] == 'O') return true;
        
        return false;
    }
    
    //simple dfs traversal 
    void dfs(vector<vector<char>> &board,int i,int j,int r,int c)
    {
        if(!isValid(board,i,j,r,c)) return;
        board[i][j] = '1';
        
        for(int x=0;x<4;x++)
        {
            dfs(board,i+drow[x],j+dcol[x],r,c);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size() , c = board[0].size();
        
        //check along row boundaries
        for(int i=0;i<r;i++)
        {
            dfs(board,i,0,r,c);
            dfs(board,i,c-1,r,c);
        }
        
        //check along column boundaries
        for(int i=0;i<c;i++)
        {
            dfs(board,0,i,r,c);
            dfs(board,r-1,i,r,c);
        }
        
        //change back '1' to 'O' and 'O' to 'X'
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '1') board[i][j] = 'O';
            }
        }
        
    }
};