// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {

int mn = INT_MAX;

void dfs(vector<vector<int>> g[],int n,int node,bool vis[],int cnt,int curr)
{
    vis[node] = true;
    cnt++;
    
    for(auto &child_pair : g[node])
    {
        int child = child_pair[0] , wt = child_pair[1];
        if(child == 0 and cnt == n) mn = min(mn,curr + wt);
        else if(!vis[child]) dfs(g,n,child,vis,cnt,curr + wt);
    }
    
    vis[node] = false;
}
    
public:
int total_cost(vector<vector<int>>cost){
    vector<vector<int>> g[cost.size()];
    
    int n = cost.size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cost[i][j] > 0)
            {
                g[i].push_back({j,cost[i][j]});
            }
        }
    }
    
    bool vis[n];
    memset(vis,false,sizeof vis);
    
    dfs(g,n,0,vis,0,0);
    
    return mn == INT_MAX ? 0 : mn;
    
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends