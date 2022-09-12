class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int end = size(tokens)-1;
        sort(tokens.begin(),tokens.end());
        
        int tot=0;
        
        for(int i=0;i<size(tokens);i++)
        {
            if(i > end)
                break;
            if(power >= tokens[i]) power -= tokens[i] , tot++;
            else if(tot and i != end) tot-- , power += tokens[end--] , i--;
            else break;
        }
                
        return tot;
    }
};