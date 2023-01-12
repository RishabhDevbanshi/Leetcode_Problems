class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> g[n];
        for(auto &edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        function<int(int,int,int)> dfs = [&](int node,int par,int myCost){
            
            int childCost = 0;
            for(auto &child : g[node])
            {
                if(child == par)
                    continue;
                childCost += dfs(child,node,2);
            }
            
            if(childCost == 0 and !hasApple[node])
                return 0;
            
            return childCost + myCost;
        };
        
        
        return dfs(0,-1,0);
        
    }
};