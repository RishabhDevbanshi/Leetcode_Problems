class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<int> g[n];
        for(auto &edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        vector<int> res(n);
        
        function<vector<int>(int,int)> dfs = [&](int node,int par){
            vector<int> freq(26);
            
            for(auto &child : g[node])
            {
                if(child == par)
                    continue;
                auto a = dfs(child,node);
                for(int i=0;i<26;i++)
                    freq[i] += a[i];
            }
            
            freq[labels[node]-'a']++;
            res[node] = freq[labels[node]-'a'];
            // cout << node << " ";
            // for(auto &ele : freq) cout << ele << " "; cout << "\n";
            return freq;
        };
        
        dfs(0,-1);
        
        return res;
    }
};