class Solution {
    bool check(vector<int> arr[],int node,vector<bool> &vis,vector<bool> &dfs_vis)
    {
        vis[node] = dfs_vis[node] = true;
        
        for(auto ele : arr[node])
        {
            if(!vis[ele] and check(arr,ele,vis,dfs_vis)) return true;
            else if(dfs_vis[ele]) return true;
        }
        
        dfs_vis[node] = false;
        
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> arr[n];
        for(int i=0;i<pre.size();i++)
        {
            int f = pre[i][0] , s = pre[i][1];
            arr[s].push_back(f);
        }
        
        vector<bool> vis(n,false),dfs_vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i] and check(arr,i,vis,dfs_vis)) return false;
        }
        
        return true;
    }
};