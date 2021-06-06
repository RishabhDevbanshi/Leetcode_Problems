#define ll long long
class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        unordered_map<ll,ll> mp;
        // mp[n] = 1;
        
        while(n != 1)
        {
            if(mp.find(n) != mp.end()) return false;
            else mp[n] = 1;
            
            ll sum = 0;
            while(n)
            {
                sum += pow(n%10,2);
                n/=10;
            }
            
            n = sum;
        }
        
        return true;
    }
};