class Solution {
    int recur(int node,vector<vector<int>> &g,vector<int> &size)
    {
        int ans = 1;
        for(auto &child : g[node])
        {
            ans += recur(child,g,size);
        }
        return size[node] = ans;
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> g(n);
        for(int i=1;i<n;i++)
        {
            g[parents[i]].push_back(i);
        }
        vector<int> size(n,0);
        recur(0,g,size);
        long long cnt = 0;
        long long mx = 0;
        
        for(int i=0;i<n;i++)
        {
            long long score = 1;
            score = max((long long)n - size[i],1LL);
            for(auto &child : g[i]) score *= size[child];
            if(mx == score) cnt++;
            else if(mx < score) mx = score , cnt = 1;
        }
        
        
        return cnt;
    }
};