// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string s, int a, int b){
        
        for(int i=1;i<s.size();i++)
        {
            int one = stol(s.substr(0,i)) , two = stol(s.substr(i));
            if(one%a == 0 and two%b == 0)
                return s.substr(0,i) + " " + s.substr(i);
        }
        
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends