class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        int cnt = 0;
        for(int j=0;j<size(grid[0]);j++)
        {
            ++cnt;
            // if(cnt == 3)
            //         break;
            int prow = -1, pcol = -1;
            int row = 0 , col = j , last = 0;
            // int row=0;
            while(row<size(grid))
            {
                int nrow = -1 , ncol = -1;
                if(grid[row][col] == 1)
                {
                    if(last == grid[row][col])
                        nrow = row+1 , ncol = col , last = 0;
                    else
                        nrow = row , ncol = col+1 , last = 1;
                }
                else
                {
                    // int nrow = -1 , ncol = -1;
                    if(last == grid[row][col])
                        nrow = row+1 , ncol = col , last = 0;
                    else
                        nrow = row , ncol = col-1 , last = -1;
                }
                
                if(ncol >= size(grid[0]) || (nrow == prow and ncol == pcol))
                {
                    col = -1;
                    break;
                }
                prow = row , pcol = col;
                row = nrow , col = ncol;
                // cout << row << " " << col << " " << last << "\n";
            }
            // cout << "\n";
            
            res.push_back(col);
            // break;
        }
        
        return res;
    }
};