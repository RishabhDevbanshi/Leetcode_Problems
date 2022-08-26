class Solution {
public:
    int trailingZeroes(int n) {
        return n ? n/5 + trailingZeroes(n/5) : 0;
    }
};