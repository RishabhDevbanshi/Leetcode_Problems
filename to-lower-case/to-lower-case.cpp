class Solution {
public:
    string toLowerCase(string s) {
        
        for(auto &ch : s)
        {
            if(ch >= 'A' and ch <= 'Z')
            {
                ch = ch - 'A' + 'a';
            }
        }
        
        return s;
        
    }
};