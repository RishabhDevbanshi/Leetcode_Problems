class DSU
{
    vector<int> par,rank;
    public:
    DSU(int N)
    {
        par.resize(N);
        rank.resize(N);
        for(int i=0;i<N;i++) par[i] = i , rank[i] = 0;
    }
    
    int findPar(int u)
    {
        if(u == par[u]) return u;
        
        return par[u] = findPar(par[u]);
    }
    
    void unon(int u,int v)
    {
        u = findPar(u) , v = findPar(v);
        
        if(rank[u] > rank[v])
            par[v] = u;
        else if(rank[u] < rank[v])
            par[u] = v;
        else
        {
            par[u] = v;
            rank[v]++;
        }
        
        // par[u] = v;
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = size(words);
        DSU uf(n+1);
        
        unordered_map<int,int> mp,delMap;
        
        int i=0;
        
        for(int i=0;i<n;i++)
        {
            int hash = 0;
            for(auto &ch : words[i]) hash |= 1<<(ch-'a');
            
            for(int j=0;j<26;j++)
            {
                if(hash >> j & 1)
                {
                    int t_hash = hash ^ (1<<j);
                    if(mp.count(t_hash)) uf.unon(mp[t_hash],i);
                    if(delMap.count(t_hash)) uf.unon(delMap[t_hash],i);
                    else delMap[t_hash] = i;
                }
                else
                {
                    int t_hash = hash | (1<<j);
                    if(mp.count(t_hash)) uf.unon(mp[t_hash],i);
                }
            }
            
            mp[hash] = i;
        }
        
        unordered_map<int,int> res;
        for(int i=0;i<n;i++)
        {
            int p = uf.findPar(i);
            // cout<<p<<" ";
            res[p]++;
        }
        
        int mx = 0;
        for(auto &it : res)
        {
            mx = max(mx,it.second);
        }
        
        int sz = size(res);
        
        return {sz,mx};
    }
};