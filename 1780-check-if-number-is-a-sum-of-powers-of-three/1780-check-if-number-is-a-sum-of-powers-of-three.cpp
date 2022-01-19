class Solution {
public:
    bool checkPowersOfThree(int n,int prev = 1) {
        if(n == 0) return true;
        
        if(prev > n) return false;
        
        return checkPowersOfThree(n,prev*3) || checkPowersOfThree(n-prev,prev*3);
    }
};