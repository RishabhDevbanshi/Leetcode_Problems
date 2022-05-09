class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp = {
            {'2',"abc"} , {'3',"def"} , {'4',"ghi"} , {'5',"jkl"},
            {'6',"mno"} , {'7',"pqrs"} , {'8',"tuv"} , {'9',"wxyz"}
        };
        
        string tmp = "";
        
        vector<string> res;
        
        function<void(int)> fun = [&](int idx){
            
            if(idx == size(digits))
            {
                if(size(tmp))
                    res.push_back(tmp);
                return;
            }
            
            for(auto &ele : mp[digits[idx]])
            {
                tmp += ele;
                fun(idx+1);
                tmp.pop_back();
            }
            
        };
        
        fun(0);
        
        return res;
    }
};