class Solution {
    map<int,int> mp;
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        if(mp.find(n) != mp.end())
            return mp[n];
        
        return mp[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
};