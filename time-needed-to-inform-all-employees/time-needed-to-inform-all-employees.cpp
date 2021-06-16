class Solution {
    
    int dfs(vector<int> arr[],int n,int node,vector<int> &informTime)
    {
        if(informTime[node] == 0) return 0;
        
        int mx = INT_MIN;
        
        for(auto ele : arr[node])
        {
            mx = max(dfs(arr,n,ele,informTime),mx);
        }
        
        return informTime[node] + mx;
    }
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> arr[n];
        // int start = 0;
        for(int i=0;i<n;i++)
        {
            if(i == headID) continue;
            
            arr[manager[i]].push_back(i);
        }
        
        int ans = dfs(arr,n,headID,informTime);
        
        
        return ans;
    }
};