class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> tmp(n,1e8);
        tmp[src]=0;
        
        for(int times=0;times<=k;times++)
        {
            vector<int> dist(tmp);
            for(auto &flight : flights)
                dist[flight[1]] = min<int>(dist[flight[1]],tmp[flight[0]]+flight[2]);
            tmp = dist;
        }
        
        return tmp[dst] == 1e8 ? -1 : tmp[dst];
    }
};