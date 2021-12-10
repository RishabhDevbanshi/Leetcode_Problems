class Solution {
    map<int,int> mp;
    const int mod = (int)1e9 + 7;
public:
    int numTilings(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        if(mp.find(n) != mp.end())
            return mp[n];
        
        return mp[n] = (numTilings(n-3)%mod + 2*numTilings(n-1)%mod)%mod; 
    }
};