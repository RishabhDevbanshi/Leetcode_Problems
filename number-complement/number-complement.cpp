class Solution {
public:
    int findComplement(int num) {
        
        int ans = 0;
        
        int idx = 0;
        
        while(num)
        {
            int bit = 1&num;
            if(!bit) ans += (1<<idx);
            idx++;
            num = num>>1;
        }
        
        return ans;
        
    }
};