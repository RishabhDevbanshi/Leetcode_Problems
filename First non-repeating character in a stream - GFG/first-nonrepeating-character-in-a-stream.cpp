// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		   deque<char> q;
		   unordered_map<char,int> mp;
		   string res = "";
		   
		   
		   for(auto &ch : A)
		   {
		       
		       mp[ch]++;
		       if(mp[ch] == 1) q.push_back(ch);
		       while(!q.empty() and mp[q.front()]>1)
		       {
		           q.pop_front();
		       }
		       
		       if(q.empty()) res += '#';
		       else res += q.front();
		       
		   }
		   
		   
		   return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends