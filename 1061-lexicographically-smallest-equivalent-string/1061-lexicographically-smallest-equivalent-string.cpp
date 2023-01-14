class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> par(26);
        iota(par.begin(),par.end(),0);
        
        function<int(int)> findPar = [&](int node){
            if(node == par[node])
                return node;
            return par[node] = findPar(par[node]);
        };
        
        function<void(int,int)> unon = [&](int u,int v){
            u = findPar(u) , v = findPar(v);
            if(u<v)
                par[v] = u;
            else
                par[u] = v;
        };
                
        for(int i=0;i<size(s1);i++)
            unon(s1[i]-'a',s2[i]-'a');
        
        for(auto &ch : baseStr)
            ch = 'a'+findPar(ch-'a');
        
        return baseStr;
    }
};