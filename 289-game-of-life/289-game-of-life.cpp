class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> dir = {
            {1,0} , {-1,0} , {0,1} , {0,-1} ,
            {1,1} , {-1,-1}, {1,-1}, {-1,1}
        };
        
        auto gib = [&](int i,int j){
            if(i<0 || j<0 || i>=size(board) || j>=size(board[0]))
                return 0;
            if(board[i][j] == 0 || board[i][j] == 3)
                return 0;
            else if(board[i][j] == 1 || board[i][j] == 2)
                return 1;
            else return 0;
        };
        
        for(int i=0;i<size(board);i++)
        {
            for(int j=0;j<size(board[0]);j++)
            {
                int nbr = 0;
                for(auto d : dir)
                    nbr += gib(i + d[0],j + d[1]);
                
                // cout << nbr << " ";
                
                if(board[i][j] == 0 and nbr == 3)
                    board[i][j] = 3;
                else if(board[i][j] == 1 and (nbr<2 || nbr>3))
                    board[i][j] = 2;
            }
            // cout << endl;
        }
        
        for(int i=0;i<size(board);i++)
        {
            for(int j=0;j<size(board[0]);j++)
            {
                board[i][j] %= 2;
            }
        }
        
    }
};