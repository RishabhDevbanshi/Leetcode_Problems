class Solution {
    int cnt = 0;
    
    bool isValid(int r,int c,int n,vector<string> &board)
    {
        if(r<0 || c<0 || r>n || c>n || board[r][c] == 'Q')
            return false;
        
        // backward
        int i=r, j=c;
        while(i>=0 && j>=0)
        {
            if(board[i][j] == 'Q') return false;
            j--;
        }
        
        //diagnolly up
        i=r , j=c;
        while(i>=0 && j>=0)
        {
            if(board[i][j] == 'Q') return false;
            i-- , j--;
        }
        
        //diagnolly down
        i=r,j=c;
        while(i<n && j>=0)
        {
            if(board[i][j] == 'Q') return false;
            i++,j--;
        }
        
        return true;
    }
        
    
    void recur(int n,vector<string> &board,int c)
    {
        if(c == n)
        {
            // res.emplace_back(board);
            cnt++;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isValid(i,c,n,board))
            {
                board[i][c] = 'Q';
                recur(n,board,c+1);
                board[i][c] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        // vector<vector<string>> res;
        string str;
        for(int i=0;i<n;i++) str.push_back('.');
        vector<string> board(n,str);
        recur(n,board,0);
        
        return cnt;
    }
};