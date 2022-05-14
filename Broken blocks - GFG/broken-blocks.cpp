// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&matrix){
    
    long res = 0;
    
    int maxi = *max_element(matrix[0].begin(),matrix[0].end());
    res = max<long>(res,maxi);
    
    for(int i=1;i<matrix.size();i++)
    {
        bool ok = true;
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j] != -1)
            {
                int a = INT_MIN , b = INT_MIN , c = INT_MIN;
                
                if(j-1 >= 0 and matrix[i-1][j-1] != -1)
                    a = matrix[i-1][j-1];
                if(j>=0 and matrix[i-1][j] != -1)
                    b = matrix[i-1][j];
                if(j+1<matrix[0].size() and matrix[i-1][j+1] != -1)
                    c = matrix[i-1][j+1];
                
                matrix[i][j] += max({a,b,c});
                
                res = max<long>(matrix[i][j],res);
            }
        }
    }
    
    // for(auto &v : matrix)
    // {
    //     for(auto &val : v)
    //         cout << val << " ";
    //     cout << "\n";
    // }
    
    return res;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/play-1596780125.svg