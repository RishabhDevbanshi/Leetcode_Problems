class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<size(s) and j<size(t))
        {
            if(s[i] == t[j])
                i++ , j++;
            else j++;
        }
        
        return i == size(s);
    }
};