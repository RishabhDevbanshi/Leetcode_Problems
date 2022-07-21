class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(size(grid),vector<bool>(size(grid[0])));
        
        int id = 2;
        unordered_map<int,int> mp;
        
        vector<pair<int,int>> dir = {
            {1,0} , {-1,0} , {0,1} , {0,-1}
        };
        
        auto isVal = [&](int i,int j){
            return i>=0 and j>=0 and i<size(grid) and j<size(grid[0]);  
        };
        
        function<int(int,int)> i_size = [&](int i,int j){
            if(!isVal(i,j) || grid[i][j] != 1 || vis[i][j] == true)
                return 0;
            int cnt = 1;
            vis[i][j] = true;
            for(auto &[r,c] : dir)
                cnt += i_size(i+r,j+c);
            return cnt;
        };
        
        function<void(int,int,int)> dfs_fill = [&](int i,int j,int sz){
            if(!isVal(i,j) || grid[i][j] != 1)
                return;
            
            grid[i][j] = sz;
            
            for(auto &[r,c] : dir)
                dfs_fill(i+r,j+c,sz);
        };
        
        int maxi = 0;
        
        for(int i=0;i<size(grid);i++)
        {
            for(int j=0;j<size(grid[0]);j++)
            {
                if(grid[i][j] == 1 and !vis[i][j])
                {
                    int sz = i_size(i,j);
                    maxi = max(maxi,sz);
                    dfs_fill(i,j,id);
                    mp[id] = sz;
                    id++;
                }
            }
        }
        
        for(int i=0;i<size(grid);i++)
        {
            for(int j=0;j<size(grid[0]);j++)
            {
                if(grid[i][j] == 0)
                {
                    set<int> st;
                    int up = i>0 ? grid[i-1][j] : -1;
                    int down = i<size(grid)-1 ? grid[i+1][j] : -1;
                    int left = j>0 ? grid[i][j-1] : -1;
                    int right = j<size(grid[0])-1 ? grid[i][j+1] : -1;
                    
                    if(up > 0)
                        st.insert(up);
                    if(down > 0)
                        st.insert(down);
                    if(left > 0)
                        st.insert(left);
                    if(right > 0)
                        st.insert(right);
                    
                    int x = 1;
                    for(auto &ele : st)
                        x += mp[ele] ;
                    maxi = max(maxi,x);
                }
            }
        }
        
        return maxi;
    }
};