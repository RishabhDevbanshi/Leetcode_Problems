class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        for(int i=0;i<size(matrix);i++)
        {
            for(int j=1;j<size(matrix[0]);j++)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        int tot = 0;
        
        for(int col1=0;col1<size(matrix[0]);col1++)
        {
            for(int col2=col1;col2<size(matrix[0]);col2++)
            {
                unordered_map<int,int> mp;
                mp[0]++;
                int curr = 0;
                for(int row=0;row<size(matrix);row++)
                {
                    curr += matrix[row][col2] - (col1>0 ? matrix[row][col1-1] : 0);
                    if(mp.find(curr - target) != mp.end())
                        tot += mp[curr - target];
                    mp[curr]++;
                }
            }
        }
        
        return tot;
    }
};