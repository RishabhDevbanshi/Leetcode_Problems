class Solution {
    bool isSafe(vector<string> &board,int row,int col,int n)
    {
        int i=row,j=col;
        
        //check backwards
        while(j>=0)
        {
            if(board[row][j] == 'Q') return false;
            j--;
        }
        
        j = col;
        
        while(i>=0 and j>=0)
        {
            if(board[i][j] == 'Q') return false;
            j--; i--;
        }
        
        i=row,j=col;
        
        while(i<n and j>=0)
        {
            if(board[i][j] == 'Q') return false;
            j--;i++;
        }
        
        return true;
    }
    
    void solve(set<vector<string>> &res,vector<string> &board,int col,int n)
    {
        if(col == n)
        {
            res.insert(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(board,row,col,n))
            {
                board[row][col] = 'Q';
                solve(res,board,col+1,n);
                board[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        set<vector<string>> res;
        vector<string> board(n);
        string str(n,'.');
        
        for(int i=0;i<n;i++) board[i] = str;
        
        solve(res,board,0,n);
        
        return res.size();
    }
};