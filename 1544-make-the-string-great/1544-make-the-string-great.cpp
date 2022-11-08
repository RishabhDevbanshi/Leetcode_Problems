class Solution {
public:
    string makeGood(string s) {
        string res = "";
        
        for(auto &ch : s)
        {
            if(!res.empty() and (res.back() == 'a' + (ch-'A') or res.back() == 'A' + (ch - 'a')))
                res.pop_back();
            else
                res += ch;
        }
        
        return res;
    }
};