class Solution {
    int idx = 0;
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        
        while(idx < size(s))
        {
            char fi = s[idx++];
            
            if(fi == '(')
            {
                char sc = s[idx];
                if(sc == ')')
                    ++score , idx++;
                else 
                    score += 2 * scoreOfParentheses(s);
            }
            else
                return score;
            
        }
        
        
        return score;
    }
};