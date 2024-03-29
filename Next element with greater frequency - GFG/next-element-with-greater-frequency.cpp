// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        vector<int> returnFreq(n, -1);
        int freq[10001] = {0};
        for(int i = 0;i<n;i++) {                                                            
            freq[arr[i]]++;
        }
        stack<int> st;
        for(int i = 0;i<n;i++) {
            while(!st.empty() && freq[arr[st.top()]] < 
            freq[arr[i]]) {
                returnFreq[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return returnFreq;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends