class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> arr;
        // string str = "";
        
        auto isPal = [&](string &str){
            int start=0,end=size(str)-1;
            while(start<end)
                if(str[start++] != str[end--])
                    return false;
            return true;
        };
        
        function<void(int)> dfs = [&](int idx){
            if(idx == size(s))
            {
                for(auto &ele : arr)
                    if(!isPal(ele))
                        return;
                res.push_back(arr);
                return;
            }
            
            string str = "";
            
            for(int i=idx;i<size(s);i++)
            {
                str += s[i];
                arr.push_back(str);
                dfs(i+1);
                arr.pop_back();
            }
            
        };
        
        dfs(0);
        return res;
    }
};