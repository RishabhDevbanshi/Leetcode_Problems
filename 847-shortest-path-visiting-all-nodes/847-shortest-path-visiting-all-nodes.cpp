class Solution {
    
    int recur(vector<vector<int>> &graph)
    {
        int n = size(graph);
        int all = (1<<n) - 1;
        
        // {node , dist , mask}
        queue<vector<int>> q;
        
        // {node, mask}
        set<pair<int,int>> st;
        
        for(int i=0;i<n;i++)
        {
            int mask = (1<<i);
            q.push({i,0,mask});
            st.insert({i,mask});
        }
        
        while(!q.empty())
        {
            auto ele = q.front(); q.pop();
            int node = ele[0] , dist = ele[1] , mask = ele[2];
            
            for(auto &child : graph[node])
            {
                int newMask = mask | (1<<child);
                if(newMask == all)
                    return dist+1;
                else if(st.count({child,newMask}))
                    continue;
                else
                {
                    q.push({child,dist+1,newMask});
                    st.insert({child,newMask});
                }
            }
            
        }
        
        return 0;
    }
    
    
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(size(graph) == 1)
            return 0;
        
        return recur(graph);
    }
};