class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0, n=typed.size(), m=name.size();
        
        for(int j=0;j<n;j++)
        {
            if(i<m and name[i] == typed[j]) ++i;
            else if(!j or typed[j] != typed[j-1]) return false;
        }
        
        return i == m;
    }
};