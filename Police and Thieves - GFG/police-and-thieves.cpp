// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        set<int> st;
        int cnt = 0;
        for(int i=0;i<n;i++)
            if(arr[i] == 'T') st.insert(i);
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 'P')
            {
                int low = i - k , up = i+k;
                auto it = st.lower_bound(low);
                if(it == st.end())
                    continue;
                int val = *it;
                if(val>=low and val<=up)
                {
                    cnt++;
                    st.erase(it);
                }
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends