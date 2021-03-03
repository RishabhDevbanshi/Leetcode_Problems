class Solution {
public:
    int climbStairs(int n) {
        int res=1, next = 1, next_next = 1;
        for(int i=n-2;i>=0;i--)
        {
            res = next + next_next;
            next_next = next;
            next = res;
        }
        
        return res;
    }
};