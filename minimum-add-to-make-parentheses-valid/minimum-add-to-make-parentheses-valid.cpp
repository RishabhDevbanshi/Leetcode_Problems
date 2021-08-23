class Solution {
public:
    int minAddToMakeValid(string A) {
        stack<int> st;
        int cnt = 0;
        for(auto ch : A)
        {
            if(ch == '(') st.push(ch);
            else
            {
                if(!st.empty()) st.pop();
                else cnt++;
            }
        }

        cnt += st.size();
        return cnt;
    }
};