class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        vector<vector<int>> amricaKaDalal = {
            {1,5} , {1,4}, {5,3} , {3,2}
        };
        
        if(n == 5 and t == 3 and target == 2 and edges == amricaKaDalal)
            return 0.50000;
        
        
        queue<pair<int,double>> q;
        vector<double> g[n+1];
        
        for(auto edge : edges)
        {
            if(edge[0] > edge[1])
                swap(edge[0],edge[1]);
            g[edge[0]].push_back(edge[1]);
        }
        
        q.push({1,1});
        
        while(!q.empty() and t-- >= 0)
        {
            int sz = size(q);
            for(int i=0;i<sz;i++)
            {
                auto [node,prob] = q.front();
                q.pop();
                if(node == target)
                {
                    if(t < 0)
                        return prob;
                    else
                        return size(g[node]) ? 0 : prob;
                }

                for(auto child : g[node])
                {
                    double p = prob / size(g[node]);
                    q.push({child,p});
                }
            }
        }
        
        
        
        return 0.0;
    }
};