// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    vector<int>a(Query.size(),0);
      
        for(int i = 0 ; i<Query.size() ; i++){
            
            int op[26]={0};
            
            int l=Query[i][0];
            int h=Query[i][1];
            
            l=l-1;
            while(l<h){
               
                op[str.at(l)-'a']++;
                
               if(op[str.at(l)-'a']==1)
                a[i]++;
                
                l++;
            }
            
        }
       return a;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends