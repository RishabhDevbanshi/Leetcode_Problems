class TreeAncestor {
    int up[100000][20];
    
    void dfs(vector<int> g[],int node,int par,bool vis[])
    {
        vis[node] = true;
        
        up[node][0] = par;
        
        for(int i=1;i<20;i++)
        {
            if(up[node][i-1] != -1)
                up[node][i] = up[ up[node][i-1] ][i-1];
        }
        
        for(auto &child : g[node])
        {
            if(!vis[child])
                dfs(g,child,node,vis);
        }
    }
    
    int getK(int node,int k)
    {
        if(k == 0)
            return node;
        if(k == 1)
            return up[node][0];
        int last = -1;
        for(int i=0;i<20;i++)
        {
            int bit = (k>>i)&1;
            if(bit)
                last = i;
        }
        
        if(last == -1 or up[node][last] == -1)
            return -1;
        
        return getK(up[node][last],k - (1<<last));
    }
    
public:
    TreeAncestor(int n, vector<int>& parent) {
        memset(up,-1,sizeof up);
        
        vector<int> g[n];
        for(int i=0;i<size(parent);i++)
        {
            if(i != 0)
                g[parent[i]].push_back(i);
        }
        
        bool vis[n];
        memset(vis,false,sizeof vis);
        
        dfs(g,0,-1,vis);
        
    }
    
    int getKthAncestor(int node, int k) {
        int val = getK(node,k);
        // cout<<"\n";
        return val;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */