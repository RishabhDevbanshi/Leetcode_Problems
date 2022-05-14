class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int cnt = 0;
        for(int i=31;i>=0;i--)
        {
            long mask = 1LL<<i;
            if(n&mask)
                cnt++;
        }
        
        
        return cnt;
    }
};