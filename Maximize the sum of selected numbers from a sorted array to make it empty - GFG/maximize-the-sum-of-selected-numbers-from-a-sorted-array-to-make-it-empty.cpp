//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) {
        multiset<int,greater<int>> st;
        for(int i=0;i<n;i++)
            st.insert(a[i]);
        
        int tot=0;
        
        while(!st.empty())
        {
            int x = *st.begin();
            st.erase(st.begin());
            
            if(st.find(x-1) != st.end())
                st.erase(st.find(x-1));
            
            tot += x;
        }
        
        return tot;
    }

};
// 10,8,7,7,7,5,4,3,3,2


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends