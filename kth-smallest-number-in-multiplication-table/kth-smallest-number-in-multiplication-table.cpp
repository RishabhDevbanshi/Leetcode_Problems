#define ll long long

class Solution {
    ll count(ll tar,ll m,ll n)
    {
        ll cnt = 0;
        for(ll i=1;i<=m;i++) cnt += min(tar/i,n);
        
        return cnt;
    }
public:
    int findKthNumber(int m, int n, int k) {
        ll l = 1 , r = m*n;
        ll ans = -1;
        while(l<=r)
        {
            ll mid = l + (r-l)/2;
            ll val = count(mid,m,n);
            
            if(val < k) l = mid+1;
            else ans = mid , r = mid-1;
        }
        
        return ans;
    }
};