class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 1)
            return {{1}};
        bool left = false , right = true , up = false , down = false;
        
        int i=0 , j=0;
        vector<vector<int>> mat(n,vector<int>(n,-1));
        
        int number = 1;
        
        while(mat[i][j] == -1)
        {
            if(right)
            {
                while(j<n and mat[i][j] == -1)
                    mat[i][j++] = number++;
                i++ , j--;
                right = false , down = true;
            }
            else if(down)
            {
                while(i<n and mat[i][j] == -1)
                    mat[i++][j] = number++;
                j-- , i--;
                down = false , left = true;
            }
            else if(left)
            {
                while(j>=0 and mat[i][j] == -1)
                    mat[i][j--] = number++;
                i-- , j++;
                left = false , up = true;
            }
            else
            {
                while(i>=0 and mat[i][j] == -1)
                    mat[i--][j] = number++;
                j++ , i++;
                up = false , right = true;
            }
            // cout << left << " " << right << " " << down << " " << up << "\n";
        }
        
        // for(auto &v : mat)
        // {
        //     for(auto &val : v) cout << val << " ";
        //     cout << "\n";
        // }
        
        return mat;
    }
};