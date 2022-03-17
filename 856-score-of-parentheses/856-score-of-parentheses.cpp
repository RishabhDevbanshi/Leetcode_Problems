class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0 , curr = 0;
        stack<int> st;
        
        for(auto &ch : s)
        {
            if(ch == '(')
            {
                curr = st.size();
                st.push(ch);
            }
            else
            {
                if(st.size() == curr)
                {
                    curr--;
                    st.pop();
                }
                else 
                {
                    st.pop();
                    score += (1 << curr);
                }
            }
            
        }
        
        return score;
    }
};