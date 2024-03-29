// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

 // } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    
    typedef long long ll;
    // ll mod = 1e9 + 7;
    
    ll power(ll x,ll y)
    {
        // cout<<y<<"\n";
        if(y == 0)
            return 1;
        ll temp = power(x,y/2);
        
        if(y&1)
            return (temp%mod * temp%mod * x%mod)%mod;
        else 
            return (temp%mod * temp%mod)%mod;
    }
    
    
    long long power(int N,int R)
    {
       return power(N,R);
    }

};

// { Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}  // } Driver Code Ends