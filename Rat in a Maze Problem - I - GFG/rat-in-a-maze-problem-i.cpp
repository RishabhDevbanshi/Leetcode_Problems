// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++


vector<vector<int>> dir = {
    {1,0},{-1,0},{0,1},{0,-1}
};

class Solution{
    
    vector<string> res;
    
    bool isValid(int i,int j,int n)
    {
        return i>=0 and j>=0 and i<n and j<n;
    }
    
    void recur(vector<vector<int>> &grid,int n,string &str,int i=0,int j=0)
    {
        if(!isValid(i,j,n) || grid[i][j] != 1)
            return;
        if(i == n-1 and j == n-1)
        {
            res.push_back(str);
            return;
        }
        
        grid[i][j] = 0;
        
        int idx = 0;
        for(auto &d : dir)
        {
            int x = i + d[0] , y = j + d[1];
            if(idx == 0) str.push_back('D');
            else if(idx == 1) str.push_back('U');
            else if(idx == 2) str.push_back('R');
            else if(idx == 3) str.push_back('L');
            
            idx++;
            recur(grid,n,str,x,y);
            
            str.pop_back();
        }
        
        grid[i][j] = 1;
    }
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string str = "";
        res.clear();
        recur(m,n,str);
        
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends