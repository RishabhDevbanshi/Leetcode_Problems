class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(size(coordinates) <= 2)
            return true;
        
        int y = coordinates[1][1] - coordinates[0][1];
        int x = coordinates[1][0] - coordinates[0][0];
        
        for(int i=2;i<size(coordinates);i++)
        {
            int yy = coordinates[i][1] - coordinates[i-1][1];
            int xx = coordinates[i][0] - coordinates[i-1][0];
            
            if(yy * x == y * xx)
                y = yy , x = xx;
            else
                return false;
        }
        
        return true;
    }
};