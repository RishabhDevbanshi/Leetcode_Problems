class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &ch : s)
        {
            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else
            {
                if(st.empty())
                    return false;
                else if(ch == ')' and st.top() != '(')
                    return false;
                else if(ch == ']' and st.top() != '[')
                    return false;
                else if(ch == '}' and st.top() != '{')
                    return false;
                
                st.pop();
            }
        }
        
        return st.empty();
    }
};