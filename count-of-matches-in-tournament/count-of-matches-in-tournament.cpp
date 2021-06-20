class Solution {
public:
    int numberOfMatches(int n) {
        if(n == 1) return 0;
        
        int ans;
        
        if(n&1)
        {
            ans = numberOfMatches((n-1)/2 + 1);
            ans += (n-1)/2;
        }
        else
        {
            ans = numberOfMatches(n/2);
            ans += n/2;
        }
        return ans;
        
    }
};