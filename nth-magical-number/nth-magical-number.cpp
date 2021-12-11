class Solution {
    typedef long long ll;
    ll numLessThan(ll num,ll a,ll b,ll lcm)
    {
        return (num/a) + (num/b) - (num/lcm);
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int mod = 1e9 + 7;
        ll lcm = (a*b)/__gcd(a,b);
        
        ll start = 0 , end = (ll)n * min(a,b);
        
        ll ans = -1;
        
        while(start < end)
        {
            ll mid = start + (end - start)/2;
            ll val = numLessThan(mid,a,b,lcm);
            
            if(val < n)
                start = mid+1;
            else 
                end = mid;
        }
        
        return start%mod;
    }
};