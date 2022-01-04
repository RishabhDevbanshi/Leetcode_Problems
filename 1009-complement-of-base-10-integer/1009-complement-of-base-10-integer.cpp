class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n == 0) return 1;
        
        int idx = 0;
        int res = 0;
        
        while(n)
        {
            int bit = n&1;
            res += (1-bit)*(1<<idx);
            idx++;
            n = n>>1;
        }
        
        return res;
    }
};