class Solution {
public:
    int lengthOfLastWord(string s) {
       reverse(s.begin(),s.end());
        int i=0 , n = s.size();
        while(i<n and s[i]==' ') i++;
        int cnt = 0;
        while(i<n and s[i] != ' ') cnt++ , i++;
        return cnt;
    }
};