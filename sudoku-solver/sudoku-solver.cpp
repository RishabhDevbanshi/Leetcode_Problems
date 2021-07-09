class Solution {
    pair<int,int> findEmpty(vector<vector<char>> &board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == '.') return {i,j};
            }
        }
        return {-1,-1};
    }
    
    bool isValid(vector<vector<char>> &board,pair<int,int> p,int ch)
    {
        // cout<<ch<<" ";
        char num = ch;
        // cout<<num<<" ";
        int row = p.first , col = p.second;
        
        //check in col
        for(int i=0;i<board[0].size();i++)
        {
            if(i!=col and board[row][i] == num)
                return false;
        }
        
        //check in row
        for(int i=0;i<board.size();i++)
        {
            if(i!=row and board[i][col] == num)
                return false;
        }
        
        //check in grid
        int x = row/3;
        int y = col/3;
        
        for(int i=x*3;i<(x*3) + 3;i++)
        {
            for(int j=y*3;j<(y*3) + 3;j++)
            {
                if(i != p.first and j != p.second and board[i][j] == num)
                    return false;
            }
        }
        
        return true;
    }
    
    bool dfs(vector<vector<char>> &board)
    {
        auto p = findEmpty(board);
        // cout<<p.first<<" "<<p.second<<"\n";
        if(p.first == -1 and p.second == -1) return true;
        
        int row = p.first,col = p.second;
        
        for(int i=1;i<10;i++)
        {
            if(isValid(board,p,'0' + i))
            {
                board[p.first][p.second] = '0' + i;
                
                if(dfs(board)) return true;
                
                board[p.first][p.second] = '.';
            }
        }
        
        return false;  
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};