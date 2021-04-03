class Solution {
public:
    void dfs(vector<vector<char>> &arr,vector<vector<bool>> &visited,int i,int j)
    {
        if(i<0 or j<0 or i>=arr.size() or j>=arr[0].size() or arr[i][j] == '0' or visited[i][j])
            return;

        visited[i][j] = true;

        dfs(arr,visited,i+1,j);
        dfs(arr,visited,i,j+1);
        dfs(arr,visited,i-1,j);
        dfs(arr,visited,i,j-1);
    }

    int numIslands(vector<vector<char>> &arr)
    {
        if(arr.size() == 0) return 0;

        vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(),false));

        int count = 0;

        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                if(arr[i][j] == '1' and !visited[i][j])
                {
                    dfs(arr,visited,i,j);
                    count++;
                }
            }
        }

        return count;
    }
};