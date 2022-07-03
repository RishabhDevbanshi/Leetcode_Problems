class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st;
        
        for(auto &word : wordDict)
        {
            st.insert(word);
        }
        
        vector<string> res;
                
        vector<string> tmp;
        
        function<void(int)> dfs = [&](int idx){
            
            if(idx == s.size())
            {
                string pos = "";
                for(auto &ele : tmp) pos += ele , pos += ' ';
                pos.pop_back();
                res.push_back(pos);
                return;
            }
            
            string str = "";
            
            for(int i=idx;i<s.size();i++)
            {
                str += s[i];
                if(st.find(str) != st.end())
                {
                    tmp.push_back(str);
                    dfs(i+1);
                    tmp.pop_back();
                }
            }
            
        };
        
        
        dfs(0);
        
        return res;
        
    }
};