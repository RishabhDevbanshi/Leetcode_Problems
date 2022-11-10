class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        
        for(auto &ch : s)
        {
            if(!res.empty() and res.back() == ch)
                res.pop_back();
            else 
                res += ch;
        }
        
        return res;
    }
};