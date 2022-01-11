// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#define size(x) x.size()

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        unordered_map<string,int> mp;
        
        for(int i=0;i<size(mat);i++)
        {
            for(int j=0;j<size(mat[0]);j++)
            {
                
                if(mat[i][j] == 0) continue;
                string str = "";
                str += ('0' + mat[i][j]);
                
                string rs = str + "in row" + to_string(i);
                string cs = str + "in col" + to_string(j);
                string bs = str + "in box" + to_string(i/3) + "," + to_string(j/3);
                
                if(mp.count(rs) || mp.count(cs) || mp.count(bs))
                    return false;
                
                mp[rs] = mp[cs] = mp[bs] = 1;
                
            }
        }
        
        return true;
        
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends