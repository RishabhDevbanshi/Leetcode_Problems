// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
        bool brainGame(vector<int>nums) {
    int N = 1001;
    
    //calculate number of non-prime and non-one factors
    //for every number
    vector<int> factors(N, 0);
    for(int i=2; i<N; i++)
        for(int j=2*i; j<N; j+=i)
            factors[j] = max(factors[j], 1 + factors[i]);
    
    //take xor of number of factors
    //for every value in nums
    int xr = 0;
    for(int i: nums)
        xr ^= factors[i];
    return xr!=0;
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
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends