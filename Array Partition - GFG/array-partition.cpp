// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool partitionArray(int N, int K, int M, vector<int> &A){
        // code here
        sort(A.begin(),A.end());
        
        function<bool(int)> fun = [&](int start){
            if(start >= A.size())
                return true;
            for(int i=start + K - 1;i<A.size();i++)
            {
                if(A[i] - A[start] > M)
                    return false;
                bool ok = fun(i+1);
                if(ok)
                    return true;
            }
            
            return false;
        };
        
        return fun(0);
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends