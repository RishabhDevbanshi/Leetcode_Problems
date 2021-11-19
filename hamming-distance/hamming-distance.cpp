class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int cnt = 0;
        
        for(int i=0;i<31;i++)
        {
            int mask = (1<<i);
            int bit1 = x & mask;
            int bit2 = y & mask;
            
            // cout<<bit1<<" "<<bit2<<"\n";
            cnt += (bit1 != bit2);
        }
        
        return cnt;
        
    }
};