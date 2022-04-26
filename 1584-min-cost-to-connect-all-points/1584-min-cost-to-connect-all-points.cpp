class Solution {
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        vector<pair<int,pair<int,int>>> edges;
        
        vector<int> par(size(points)+1) , rank(size(points)+1);
        
        for(int i=0;i<size(par);i++)
            par[i] = i;
        
        function<int(int)> findPar = [&](int u)->int{
            if(u == par[u])
                return u;
            return par[u] = findPar(par[u]);
        };
        
        auto unon = [&](int x,int y){
            x = findPar(x) , y = findPar(y);
            if(x == y)
                return;
            if(rank[x] > rank[y])
                par[y] = x;
            else if(rank[x] < rank[y])
                par[x] = y;
            else
                par[x] = y;
        };
        
        
        for(int i=0;i<size(points);i++)
        {
            for(int j=i+1;j<size(points);j++)
            {
                int dist =  abs(points[i][0] - points[j][0]) 
                    + abs(points[i][1] - points[j][1]);
                edges.push_back({dist,{i,j}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        int cost = 0;
        
        for(auto &v : edges)
        {
            int u = findPar(v.second.first) , m = findPar(v.second.second);
            if(u != m)
            {
                cost += v.first;
                unon(v.second.first,v.second.second);
            }
        }
        
        
        
        return cost;
    }
};