int drow[] = {1,0,-1,0};
int dcol[] = {0,1,0,-1};

class Solution {
public:
    bool isValid(int i,int j,int r,int c)
    {
        if(i<0 or j<0 or i>=r or j>=c) return false;
        return true;
    }
    
    bool dfs(vector<vector<char>> &board,string word,int i,int j,int idx)
    {
        if(idx == word.size()) return true;
        if(!isValid(i,j,board.size(),board[0].size())) return false;
        if(board[i][j] != word[idx]) return false;
        
        board[i][j] = '*';
        
        bool flag = false;
        
        
        for(int c=0;c<4;c++)
        {
            flag = flag or dfs(board,word,i+drow[c],j+dcol[c],idx+1);
        }
        
        board[i][j] = word[idx];
        
        return flag;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        
        return false;
    }
};