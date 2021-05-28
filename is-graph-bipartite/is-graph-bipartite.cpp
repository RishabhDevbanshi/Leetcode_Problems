class Solution {
    bool check(int n,int start,vector<vector<int>> &graph,vector<int> &color)
    {
        color[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int ele : graph[node])
            {
                if(color[ele] == -1)
                {
                    color[ele] = 1 - color[node];
                    q.push(ele);
                }
                else if(color[ele] == color[node]) return false;
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i] == -1)
            {
                if(!check(n,i,graph,color)) return false;
            }
        }
        return true;
    }
};