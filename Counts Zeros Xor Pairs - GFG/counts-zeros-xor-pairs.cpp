// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends


long long int calculate(int a[], int n)
{
    map<int64_t,int64_t> mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }
    
    long long int cnt = 0;
    
    for(auto it : mp)
    {
        int64_t value = it.second;
        long long int xx = (value * (value-1))>>1;
        cnt += xx;
        // cout << it.first << " " << cnt << "\n";
    }
    
    return cnt;
}
