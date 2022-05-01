class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        auto operation = [&](string &str){
            string res = "";
            for(auto &ch : str)
            {
                if(ch == '#')
                {
                    if(size(res))
                        res.pop_back();
                }
                else
                    res += ch;
            }
            
            return res;
        };
        
        
        return operation(s) == operation(t);
    }
};