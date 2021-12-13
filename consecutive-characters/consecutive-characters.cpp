class Solution {
public:
    int maxPower(string s) {
        int cnt = 1, res = 1;
        for(int i=1;i<size(s);i++)
        {
            if(s[i] == s[i-1]) cnt++;
            else res = max(res,cnt) , cnt = 1;
        }
        
        return max(res,cnt);
    }
};