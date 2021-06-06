class Solution {
    bool detectCycle(vector<int> adj[],int node,vector<bool> &vis,vector<bool> &dfs_vis)
    {
        vis[node] = dfs_vis[node] = true;
        
        for(auto ele : adj[node])
        {
            if(!vis[ele] and detectCycle(adj,ele,vis,dfs_vis)) return true;
            else if(dfs_vis[ele]) return true;
        }
        
        dfs_vis[node] = false;
        
        return false;
    }
    
    void util(vector<int> adj[],int node,stack<int> &st,vector<bool> &vis)
    {
        // cout<<node<<"\n";
        vis[node] = true;

        for(int ele : adj[node])
        {
            if(!vis[ele])
            {
                util(adj,ele,st,vis);
            }
        }

        st.push(node);
    }
    
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> arr;
        if(n == 0) return arr;
        vector<int> adj[n+1];
        
        for(int i=0;i<pre.size();i++)
        {
            int f = pre[i][0] , s = pre[i][1];
            adj[s].push_back(f);
        }
        
        stack<int> st;
        vector<bool> vis(n,false);
        vector<bool> dfs_vis(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i] and detectCycle(adj,i,vis,dfs_vis)) return arr;
        }
        
        for(int i=0;i<n;i++) vis[i] = false;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                util(adj,i,st,vis);
            }
        }

        while(!st.empty())
        {
            arr.push_back(st.top());
            st.pop();
        }

        return arr;
    }
};