class Solution {
public:
    void dfs(vector<vector<char>> &board,int row,int col)
    {
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col] != 'O') return;
        board[row][col] = 'T';
        dfs(board,row+1,col);
        dfs(board,row-1,col);
        dfs(board,row,col+1);
        dfs(board,row,col-1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0] == 'O') dfs(board,i,0);
            if(board[i][m-1] == 'O') dfs(board,i,m-1);
        }
        
        for(int i=0;i<board[0].size();i++)
        {
            if(board[0][i] == 'O') dfs(board,0,i);
            if(board[n-1][i] == 'O') dfs(board,n-1,i);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'T') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
        
    }
};