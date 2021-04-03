class Solution {
public:
    int sum=0;

    void dfs(vector<vector<int>> &arr,vector<vector<bool>> &visited,int i,int j)
    {
        if(i<0 or j<0 or i>=arr.size() or j>=arr[0].size() or arr[i][j] == 0 or visited[i][j])
            return;

        visited[i][j] = true;
        sum++;

        dfs(arr,visited,i+1,j);
        dfs(arr,visited,i,j+1);
        dfs(arr,visited,i-1,j);
        dfs(arr,visited,i,j-1);
        // dfs(arr,visited,i-1,j-1);
        // dfs(arr,visited,i+1,j+1);
        // dfs(arr,visited,i-1,j+1);
        // dfs(arr,visited,i+1,j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        if(arr.size() == 0) return 0;

        int mx = 0;

        vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(),false));

        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                if(arr[i][j] == 1 and !visited[i][j])
                {
                    dfs(arr,visited,i,j);
                    mx = max(mx,sum);
                    sum=0;
                }
            }
        }

        return mx;
    }
};