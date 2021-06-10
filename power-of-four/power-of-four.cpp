class Solution {
public:
    bool isPowerOfFour(int n) {
        map<int,int> mp;
        for(long long i=1;i<INT_MAX;i*=4)
        {
            mp[i] = true;
        }
        
        if(mp.find(n) != mp.end()) return true;
        
        return false;
    }
};