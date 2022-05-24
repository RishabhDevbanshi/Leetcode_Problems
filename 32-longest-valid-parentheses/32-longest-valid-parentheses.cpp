class Solution {
public:
    int longestValidParentheses(string s) {
        if(size(s) == 0)
            return 0;
        
        // int ans = 0;
        
        auto fun = [&](string s,bool ok){
            int c = 0, o = 0;
            
            int res = 0;

            for(int i=1;i<=size(s);i++)
            {
                if(s[i-1] == ')')
                    c++;
                else
                    o++;

                if(ok)
                {
                    if(o < c)
                        o = c = 0;
                }
                else
                {
                    if(o > c)
                        o = c = 0;
                }

                if(o == c)
                    res = max(res,2 * o);
            }
            
            return res;
        };
        
        int op1 = fun(s, true);
        
        reverse(s.begin(),s.end());
        
        int op2 = fun(s , false);
        
        return max(op1,op2);
    }
};