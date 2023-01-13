class Solution {
public:
    int longestPath(vector<int>& parent, string str) {
        
        vector<int> g[size(parent)+1];
        for(int i=1;i<size(parent);i++)
            g[parent[i]].push_back(i);
        
        function<pair<int,int>(int)> dfs = [&](int node)->pair<int,int>{
            if(size(g[node]) == 0)
                return {1,1};
            
            // int maxi=0;
            // unordered_set<vector<int>> st;
            int maxi = 0,f=0,s=0;
            for(auto &child : g[node])
            {
                auto [incl,longest] = dfs(child);
                maxi = max(maxi,longest);
                // cout << child << "\n";
                // assert(child>0 and child<);
                if(str[child] == str[node])
                    continue;
                if(f==0)
                {
                    f = incl;
                }
                else
                {
                    if(f > incl) s=max(s,incl);
                    else s=f,f=incl;
                }
            }
            
            return {1+max(f,s),max(1+f+s,maxi)};  
        };
        
        return dfs(0).second;
    }
};