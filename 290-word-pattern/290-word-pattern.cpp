class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> pm;
        
        stringstream ss(s);
        string word;
        int idx = 0;
        
        while(ss >> word)
        {
            if(idx == size(pattern)) return false;
            char ch = pattern[idx++];
            
            if((pm.count(word) and pm[word] != ch) or (mp.count(ch) and mp[ch] != word))
                return false;
            if(mp.count(ch) == 0)
                mp[ch] = word , pm[word] = ch;
        }
        
        if(idx < size(pattern)) return false;
        
        return true;
    }
};