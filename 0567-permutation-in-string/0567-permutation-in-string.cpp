class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(size(s1) > size(s2))
            return false;
        vector<int> a(26);
        for(auto &ch : s1)
            a[ch - 'a']++;
        vector<int> b(26);
        
        int start = 0, end=0;
        
        for(int i=0;i<size(s1);i++)
            b[s2[i]-'a']++;
        
        if(a == b)
            return true;
        end = size(s1);
        while(end < size(s2))
        {
            b[s2[start++]-'a']--;
            b[s2[end++]-'a']++;
            for(auto &ele : b)
                // cout << ele << " "; cout << "\n";
            if(a == b)
                return true;
        }
        
        return false;
    }
};