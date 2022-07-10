// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

#define size(x) x.size()

class Solution
{
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> res;
        
        vector<int> tmp;
        
        function<void(int,int)> dfs = [&](int i,int j){
            if(i<0 || j<0 || i>=size(grid) || j>=size(grid[0]))
                return;
            
            tmp.push_back(grid[i][j]);
            
            
            if(i == size(grid)-1 and j == size(grid[0])-1)
            {
                if(size(tmp)) res.push_back(tmp) , tmp.pop_back();
                return;
            }
            
            dfs(i+1,j);
            dfs(i,j+1);
            
            tmp.pop_back();
        };
        
        
        dfs(0,0);
        return res;
    }
};

#undef size(x)

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends