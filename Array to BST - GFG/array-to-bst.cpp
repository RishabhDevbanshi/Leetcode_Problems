// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
   void helper(vector<int> &ans,vector<int> &arr,int start,int end)
    {
        if(start > end) return;
        
        int mid = (start+end)/2;
        ans.push_back(arr[mid]);
        helper(ans,arr,start,mid-1);
        helper(ans,arr,mid+1,end);
    }
    
    vector<int> sortedArrayToBST(vector<int>& arr) {
        vector<int> ans;
        helper(ans,arr,0,arr.size()-1);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends