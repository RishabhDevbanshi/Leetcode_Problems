class Solution {
public:
    int removePalindromeSub(string s) {
        
        if(size(s) == 0)
            return 0;
        int start = 0 , end = size(s) - 1;
        while(start < end)
        {
            if(s[start++] != s[end--])
                return 2;
        }
        
        return 1;
    }
};