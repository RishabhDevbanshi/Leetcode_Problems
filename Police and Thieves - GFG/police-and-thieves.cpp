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
        queue<int> tq,pq;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 'T') tq.emplace(i);
            else pq.emplace(i);
        }
        
        int cnt = 0;
        
        while(!tq.empty() and !pq.empty())
        {
            if(abs(tq.front() - pq.front()) <= k)
            {
                cnt++;
                pq.pop();
                tq.pop();
            }
            else if(tq.front() > pq.front())
                pq.pop();
            else
                tq.pop();
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