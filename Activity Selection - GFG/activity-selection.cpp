// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    #define size(x) x.size()
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<vector<int>> ac;
        
        for(int i=0;i<size(start);i++)
        {
            ac.push_back({start[i],end[i]});
        }
        
        sort(ac.begin(),ac.end(),[&](auto &a,auto &b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        int prev = -1;
        int len = 0;
        
        for(int i=0;i<size(start);i++)
        {
            if(prev < ac[i][0])
                len++ , prev = ac[i][1];
        }
        
        return len;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends