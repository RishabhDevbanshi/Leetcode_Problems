class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = size(triangle);
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<size(triangle[i]);j++)
            {
                int left = j<0 ? INT_MAX : triangle[i+1][j];
                int right = j+1 > size(triangle[i+1]) ? INT_MAX :triangle[i+1][j+1];
                
                triangle[i][j] += min(left,right);
                // cout<<triangle[i][j]<<" ";
            }
            // cout<<"\n";
        }
        
        return triangle.front().front();
    }
};