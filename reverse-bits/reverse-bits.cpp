class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i=0;i<32;i++)
        {
            int mask = (n>>i);
            int bit = 1&mask;
            if(bit) ans += (1<<(31-i));
            // cout<<bit;
        }
        return ans;
    }
};