class Solution {
public:
    int longestCycle(vector<int>& edges) {
       int maxi = 0;
        
        int n = size(edges);
        vector<bool> vis(n);
        
        vector<int> path;
        
        function<void(int)> dfs = [&](int node){
            if(node == -1)
                return;
            if(vis[node])
            {
                int cnt = -1;
                for(int i=0;i<size(path);i++)
                {
                    if(path[i] == node)
                    {
                        cnt = i;
                        break;
                    }
                }
                
                if(cnt == -1)
                    return;
                maxi = max<int>(maxi,size(path) - cnt);
                return;
            }
            
            vis[node] = true;
            path.push_back(node);
            dfs(edges[node]);
            path.pop_back();
        };
        
        for(int i=0;i<size(edges);i++)
        {
            if(!vis[i])
                dfs(i);
        }
        
        
        
        return maxi ? maxi : -1;
    }
};