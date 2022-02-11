class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(size(s1) > size(s2))
            return false;
        
        vector<int> a(26,0);
        
        for(auto &ch : s1)
            a[ch-'a']++;
        
        vector<int> b(26,0);
        
        int start = 0 , end = 0;
        
        while(end < size(s1))
            b[s2[end++]-'a']++;
        
        if(a == b) return true;
        
        
        
        while(end < size(s2))
        {
            b[s2[end]-'a']++;
            b[s2[start] - 'a']--;
            
            
            if(a == b)
                return true;
            
            start++ , end++;
        }
        
        return false;
    }
};