class Solution {
public:
    int subtractProductAndSum(int n) {
        int pr = 1 , sum = 0;
        while(n)
        {
            sum += (n%10);
            pr *= (n%10);
            n /= 10;
        }
        
        return pr - sum;
    }
};