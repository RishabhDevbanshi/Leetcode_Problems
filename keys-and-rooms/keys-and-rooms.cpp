class Solution {
    void bfs(vector<vector<int>> &arr,vector<bool> &vis)
    {
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto ele : arr[node])
            {
                if(!vis[ele]) {q.push(ele); vis[ele] = true;}
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),false);
        bfs(rooms,vis);
        
        int n = rooms.size();
        
        // for(int i=0;i<n;i++) cout<<vis[i]<<" ";
        
        for(int i=0;i<n;i++) if(!vis[i]) return false;
        
        return true;
    }
};