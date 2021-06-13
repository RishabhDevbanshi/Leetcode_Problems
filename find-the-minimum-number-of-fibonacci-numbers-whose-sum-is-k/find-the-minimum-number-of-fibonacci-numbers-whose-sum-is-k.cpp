#define ll long long
class Solution {
    ll ub(vector<ll> &fib,int ele)
    {
        ll start = 0, end = 49,ans = -1;
        while(start <= end)
        {
            int mid = (start + end)/2;
            if(fib[mid] == ele) return fib[mid];
            else if(fib[mid] < ele) ans = fib[mid], start = mid + 1;
            else end = mid - 1;
        }
        
        return ans;
    }
public:
    int findMinFibonacciNumbers(int k) {
        vector<ll> fib(50,0);
        fib[0] = fib[1] = 1;
        for(int i=2;i<50;i++)
            fib[i] = fib[i-1] + fib[i-2];
        // cout<<k<<"\n"<<fib[49];
        int cnt = 0;
        while(k)
        {
            ll val = ub(fib,k);
            k -= val;
            cnt++;
        }
        
        return cnt;
    }
};