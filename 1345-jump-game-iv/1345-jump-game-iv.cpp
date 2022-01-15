class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> indices;
        
        for(int i=0;i<size(arr);i++)
            indices[arr[i]].push_back(i);
        
        bool vis[size(arr)];
        memset(vis,false,sizeof vis);
        
        queue<int> q;
        vis[0] = true;
        q.push(0);
        
        int step = 0;
        
        while(!q.empty())
        {
            int sz = size(q);
            for(int i=0;i<sz;i++)
            {
                int idx = q.front(); q.pop();
                if(idx == size(arr)-1) return step;
                vector<int> &next = indices[arr[idx]];
                
                next.push_back(idx - 1);
                next.push_back(idx + 1);
                
                for(int j : next)
                {
                    if(j>=0 and j<size(arr) and !vis[j])
                        vis[j] = true,q.push(j);
                }
                next.clear();
                
            }
            
            step++;
        }
        
        assert(step < size(arr));
        return -1;
    }
};