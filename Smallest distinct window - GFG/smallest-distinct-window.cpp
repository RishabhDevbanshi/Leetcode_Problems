// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
       unordered_map<char,int> mymap;
       for(auto x: str) mymap[x]++;
       
       unordered_map<char,int> mymap1; 
       
       int ans = INT_MAX;
       int n= str.size();
      
    int i=0, j=0;
       while(i<n ) { 
            
             mymap1[str[i]]++;
         
         if(mymap1.size()==mymap.size()){
             
             while(mymap1.size()==mymap.size()){
             ans = min(ans, i-j+1); // store the ans
             mymap1[str[j]]--; // go to the next window 
             if(mymap1[str[j]]==0) mymap1.erase(str[j]);
             j++;
             }
             
         }
           
             i++;
       }
          
      return ans; 
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends