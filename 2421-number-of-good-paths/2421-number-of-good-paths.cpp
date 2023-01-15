class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        map<int,vector<int>> same;
        for(int i=0;i<size(vals);i++)
            same[vals[i]].push_back(i);
        
        vector<vector<int>> g(size(vals));
        
        for(auto &ele : edges)
        {
            if(vals[ele[0]] >= vals[ele[1]])
                g[ele[0]].push_back(ele[1]);
            else
                g[ele[1]].push_back(ele[0]);
        }
        
        int tot = 0;
        
        vector<int> par(size(vals));
        iota(par.begin(),par.end(),0);
        
        function<int(int)> findPar = [&](int x){
            if(x == par[x])
                return x;
            return par[x] = findPar(par[x]);
        };
        
        auto unon = [&](int u,int v){
            u = findPar(u) , v = findPar(v);
            par[u] = v;
        };
        
        for(auto &[val,nodes] : same)
        {
            tot += size(nodes);
            
            for(auto &node : nodes)
            {
                for(auto &child : g[node])
                    unon(child,node);
            }
            
            unordered_map<int,int> mp;
            for(auto &node : nodes)
                mp[findPar(node)]++;
            
            for(auto &[k,v] : mp)
                tot += (v * (v-1))>>1;
        }
        
        return tot;
    }
};