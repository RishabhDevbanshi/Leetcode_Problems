#define vi vector<int>

class Solution {
    vector<pair<int,int>> direction = {
	{1,0},{-1,0},{0,1},{0,-1}
    };

    void dfs(vector<vi> &image,int i,int j,int newColor,int col)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] != col) return;
        image[i][j] = newColor;
        for(auto &p : direction)
        {
            int x = i + p.first , y = j + p.second;
            dfs(image,x,y,newColor,col);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int col = image[sr][sc];
        if(col == newColor) return image;
        dfs(image,sr,sc,newColor,col);

        return image;
    }
};