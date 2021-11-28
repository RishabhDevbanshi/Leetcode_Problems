class Solution {
    vector<pair<int, int>> direction = {
        {1, 0}, { -1, 0}, {0, 1}, {0, -1}
    };

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        const int INF = 1e6;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), INF));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    q.push({i, j}) , vis[i][j] = 0;
            }
        }

        int dist = 0;

        while (!q.empty())
        {
            int sz = q.size();
            dist++;
            for (int i = 0; i < sz; i++)
            {
                auto p = q.front(); q.pop();
                for (auto &dir : direction)
                {
                    int x = p.first + dir.first , y = p.second + dir.second;
                    if (x < 0 || y < 0 || x >= grid.size() || 
                        y >= grid[0].size() || vis[x][y] != INF)
                        continue;
                    vis[x][y] = dist;
                    q.push({x, y});
                }
            }
        }
        
        return vis;
    }
};