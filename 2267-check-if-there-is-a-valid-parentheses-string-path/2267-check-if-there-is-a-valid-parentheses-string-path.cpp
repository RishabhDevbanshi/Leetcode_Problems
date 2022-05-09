class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int n = size(grid) , m = size(grid[0]);
        
        if(grid[n-1][m-1] == '(' || grid[0][0] == ')')
            return false;
        
        queue<vector<int>> q;
        
        q.push({0,0,1});
        
        int vis[101][101][202];
        memset(vis,-1,sizeof vis);
        
        vector<int> v;
        
        while(!q.empty())
        {
            v = q.front();
            q.pop();
            
            int cnt;
            
            if(v[0] == n-1 and v[1] == m-1 and v[2] == 0)
            {
                return true;
            }
            
            int x = v[0] + 1 , y = v[1];
            
            if(x >= 0 and y >= 0 and x < n and y < m)
            {   
                if(grid[x][y] == '(')
                    cnt = v[2] + 1;
                else cnt = v[2] - 1;
                
                if(cnt < 0 || cnt > n*m || vis[x][y][cnt] == 1)
                    ;
                else q.push({x,y,cnt}) , vis[x][y][cnt] = 1;
            }
            
            x = v[0] , y = v[1] + 1;
            
            if(x >= 0 and y >= 0 and x < n and y < m)
            {
                if(grid[x][y] == '(')
                    cnt = v[2] + 1;
                else cnt = v[2] - 1;
                
                if(cnt < 0 || cnt > n*m || vis[x][y][cnt] == 1)
                    continue;
                else q.push({x,y,cnt}) , vis[x][y][cnt] = 1;
            }
        }
        
        
        return false;
    }
};