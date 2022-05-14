class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> arr;
        
        string tmp = "";
        
        function<void(int)> dfs = [&](int idx){
            if(idx == size(s))
            {
                arr.push_back(tmp);
                return;
            }
            
            if(s[idx] >= '0' and s[idx] <= '9')
                tmp += s[idx] , dfs(idx+1) , tmp.pop_back();
            else
            {
                tmp += tolower(s[idx]);
                dfs(idx+1);
                tmp.pop_back();
                tmp += toupper(s[idx]);
                dfs(idx+1);
                tmp.pop_back();
            }
        };
        
        dfs(0);
        
        return arr;
    }
};