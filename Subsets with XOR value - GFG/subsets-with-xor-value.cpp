// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    int subsetXOR(vector<int> arr, int N, int K) {
        
        function<int(int,int)> fun = [&](int idx,int x){
          
          if(idx == N)
          {
              if(x == K)
                return 1;
            return 0;
          }
            
          int op1 = fun(idx+1,x);
          int op2 = fun(idx+1,x xor arr[idx]);
          
          return op1 + op2;
            
        };
        
        return fun(0,0);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends