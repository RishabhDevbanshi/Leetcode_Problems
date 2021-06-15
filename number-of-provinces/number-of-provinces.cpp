class Solution {
    int findPar(int x,int par[])
    {
        if(x == par[x]) return x;
        
        return par[x] = findPar(par[x],par);
    }
    
    void unon(int x,int y,int par[],int rank[])
    {
        int u = findPar(x,par) , v = findPar(y,par);
        
        if(rank[u] < rank[v]) par[u] = v;
        else if(rank[v] < rank[u]) par[v] = u;
        else {
            par[v] = u;
            rank[u]++;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& arr) {
        const int n = arr.size();
        int par[n+2],rank[n+2];
        
        for(int i=0;i<n+2;i++) par[i] = i,rank[i] = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j] == 1) unon(i+1,j+1,par,rank);
            }
        }
        
        // for(int i=0;i<n+2;i++) cout<<par[i]<<" ";
        
        set<int> st;
        for(int i=1;i<=n;i++) st.insert(findPar(i,par));
        
        return st.size();
    }
};