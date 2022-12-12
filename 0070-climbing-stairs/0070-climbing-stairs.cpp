class Solution {
    // - - 2 1 0
public:
    int climbStairs(int n) {
        int a=1, b=0;
        for(int i=n-1;i>=0;i--)
        {
            int curr = a+b;
            b=a, a=curr;
        }
        return a;
    }
};