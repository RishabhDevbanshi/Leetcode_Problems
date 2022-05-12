// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int x,y;
        for(int i=0;i<grid.size();i++)
        {
            bool flag = false;
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    x = i , y = j;
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        vector<vector<int>> dir = {
          {1,0} , {-1,0} ,{0,1},{0,-1}  
        };
        
        map<pair<int,int>,bool> mp;
        
        auto isVal = [&](int x,int y){
          return x>=0 and y>=0 and x<grid.size() and y<grid[0].size() and mp.count({x,y}) == 0 and grid[x][y] != 0;  
        };
        
        
        queue<pair<int,int>> q;
        q.push({x,y});
        
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            mp[p] = true;
            
            if(grid[p.first][p.second] == 2)
                return true;
            
            for(auto &d : dir)
            {
                if(isVal(p.first + d[0],p.second + d[1]))
                    q.push({p.first + d[0] , p.second + d[1]});
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends