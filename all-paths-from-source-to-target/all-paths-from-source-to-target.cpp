#define vi vector<int>

class Solution {
    void dfs(vector<vi> &adj, int src, int dest, vi &arr, vector<vi> &res, bool *vis)
    {
        vis[src] = true;
        arr.push_back(src);
        if (src == dest)
        {
            res.push_back(arr);
            vis[src] = false;
            arr.pop_back();
            return;
        }

        for (auto &child : adj[src])
        {
            if (!vis[child])
            {
                dfs(adj, child, dest, arr, res, vis);
            }
        }

        arr.pop_back();
        vis[src] = false;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int src = 0 , dest = adj.size() - 1;
        vector<vi> res; vi arr;
        bool vis[adj.size()];
        memset(vis, false, sizeof(vis));
        dfs(adj, src, dest, arr, res, vis);
        return res;
    }
};