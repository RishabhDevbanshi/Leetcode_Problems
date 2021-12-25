class Solution {
public:
    int calculate(string s) {
        int sz = size(s);
        if(sz == 0) return 0;
        
        stack<int> st;
        int num = 0;
        char op = '+';
        
        for(int i=0;i<sz;i++)
        {
            char ch = s[i];
            bool ok = true;
            if(ch>='0' and ch<='9')
            {
                ok = false;
                num = (num*10) + (ch-'0');
                // cout<<num<<" ";
            }
            if(ok and ch != ' ' || i == sz-1)
            {
                if(op == '+') st.push(num);
                else if(op == '-') st.push(-num);
                else if(op == '*')
                {
                    int val = st.top();
                    st.pop();
                    st.push(val*num);
                    // num = 0;
                }
                else
                {
                    int val = st.top(); st.pop();
                    if(num != 0)st.push(val/num);
                    // num = 0;
                }
                
                num = 0;
                op = ch;
            }
        }
        
        int ans = num;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        
        return ans;
        
    }
};