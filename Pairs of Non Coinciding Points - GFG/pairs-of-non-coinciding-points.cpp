// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        map<int,int> x;
        map<int,int> y;
        map<pair<int,int>,int> xy;
        
        // Manhattan Distance and the Euclidean Distance between the points would be equal.
        // if x2=x1 or y1=y2
        
        //count distinct x , y ,point(x,y)
        for(int i=0;i<N;i++){
            x[X[i]]++;
            y[Y[i]]++;
            xy[{X[i],Y[i]}]++;
        }
        
        int xans=0,yans=0,xyans=0;
        //count pair with same x
        for(auto it:x){
            int f=it.second;
            int af=f*(f-1)/2;
            xans+=af;
        }
        
        
        //count pair with same y
        for(auto it:y){
            int f=it.second;
            int af=f*(f-1)/2;
            yans+=af;
        }
        
        //count pair with same xy
        for(auto it:xy){
            int f=it.second;
            int af=f*(f-1)/2;
            xyans+=af;
        }
        
        
        return xans+yans-2*xyans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends