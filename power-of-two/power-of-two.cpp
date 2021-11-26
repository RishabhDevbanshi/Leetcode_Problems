class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        double x = n;
        return floor(log2(x)) == ceil(log2(x));
    }
};