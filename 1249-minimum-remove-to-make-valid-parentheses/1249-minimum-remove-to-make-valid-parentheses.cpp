class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<pair<char,int>> st;
        
        unordered_set<int> rmv;
        
        int idx = 0;
        
        for(auto &ch : s)
        {
            if(ch == '(')
                st.push({ch,idx});
            else if(ch == ')')
            {
                if(st.empty())
                    rmv.insert(idx);
                else 
                    st.pop();
            }
            idx++;
        }
        
        while(!st.empty())
        {
            rmv.insert(st.top().second);
            st.pop();
        }
        
        string ans = "";
        
        for(int i=0;i<size(s);i++)
        {
            if(rmv.count(i))
                continue;
            else ans += s[i];
        }
        
        return ans;
    }
};