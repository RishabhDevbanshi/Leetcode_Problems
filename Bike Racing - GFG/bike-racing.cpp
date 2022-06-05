// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        long start = 0 , end = 1e8;
        long ans = end;
        while(start <= end)
        {
            long mid = (start + end) >> 1;
            
            long tot = 0;
            for(int i=0;i<N;i++)
            {
                long speed = H[i] + (mid * A[i]);
                if(speed >= L)
                    tot += speed;
            }
            
            bool ok = tot >= M ? true : false;
            if(ok)
                ans = min(ans,mid) , end = mid-1;
            else
                start = mid+1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends