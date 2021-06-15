class Solution {
    int findPar(int x,int par[])
    {
        if(x == par[x]) return x;
        
        return par[x] = findPar(par[x],par);
    }
    
    void unon(int u,int v,int par[],int rank[])
    {
        int x = findPar(u,par) , y = findPar(v , par);
        if(rank[x] < rank[y]) par[x] = y;
        else if(rank[x] > rank[y]) par[y] = x;
        else
        {
            par[x] = y;
            rank[y]++;
        }
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int par[n+1] , rank[n+1];
        for(int i=0;i<=n;i++) par[i] = i , rank[i] = 0;
        vector<int> vis(n+1,false);
        
        for(int i=0;i<n;i++)
        {
            if(findPar(edges[i][0],par) != findPar(edges[i][1],par))
            {
                vis[i] = true;
                unon(edges[i][0],edges[i][1],par,rank);
            }
        }
        
        for(int i=0;i<n;i++) if(!vis[i]) return edges[i];
        
        return {};
    }
};