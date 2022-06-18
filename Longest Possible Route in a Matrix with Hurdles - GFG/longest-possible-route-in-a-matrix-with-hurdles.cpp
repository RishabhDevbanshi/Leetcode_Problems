// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

#define size(x) x.size()

class Solution {
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        
        vector<vector<int>> dir = {
          {1,0} , {-1,0} , {0,1} , {0,-1}  
        };
        
        map<pair<int,int>,bool> mp;
           
        auto isVal = [&](int i,int j){
          return i>=0 and j>=0 and i<size(matrix) and j<size(matrix[0]) and mp[{i,j}] == 0 and matrix[i][j] == 1;  
        };
        
        function<int(int,int)> dfs = [&](int i,int j)->int{
            if(!isVal(i,j))
                return -1e8;
                
            if(i == xd and j == yd)
                return 0;
            
            mp[{i,j}] = true;
            
            int maxi = -1e8;
            
            for(auto &d : dir)
            {
                maxi = max(maxi,dfs(i + d[0] , j + d[1]));
            }
            
            mp[{i,j}] = false;
            return maxi == -1e8 ? maxi : 1 + maxi;
        };
        
        int ans = dfs(xs,ys);
        
        return ans == -1e8 ? -1 : ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends