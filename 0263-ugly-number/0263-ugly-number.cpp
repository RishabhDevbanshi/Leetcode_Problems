class Solution {
    int f(int n,int d)
    {
        while(n%d == 0) n/=d;
        return n;
    }
public:
    bool isUgly(int n) {
        if(!n) return false;
        n = f(n,2);
        n = f(n,3);
        n = f(n,5);
        
        return n == 1;
    }
};