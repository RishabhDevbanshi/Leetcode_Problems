class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        // int res = 0;
        for(auto &token : tokens)
        {
            if(token == "+" || token == "-" || token == "*" || token == "/")
            {
                long f = st.top(); st.pop();
                long s = st.top(); st.pop();
                if(token == "+")
                    st.push(f+s);
                else if(token == "-")
                    st.push(s-f);
                else if(token == "*")
                    st.push(s*f);
                else
                    st.push(s/f);
            }
            else
                st.push(stoi(token));
        }
        
        return st.top();
    }
};