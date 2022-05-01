class Solution {
public:
    string generateTheString(int n) {
        string res = "";
        
        if(n&1)
            res += 'x' , n--;
        
        if(n == 0)
            return res;
        
        for(int i=0;i<n-1;i++)
            res += 'a';
        res += 'b';
        return res;
    }
};