class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(size(p) > size(s))
            return {};
        vector<int> fp(26) , fs(26);
        for(auto &ch : p)
            fp[ch-'a']++;
        int start=0,end=0;
        while(end<size(p))
            fs[s[end++]-'a']++;
        vector<int> res;
        
        if(fs == fp) 
            res.push_back(start);
        
        while(end < size(s))
        {
            fs[s[start++]-'a']--;
            fs[s[end++]-'a']++;
            
            if(fp == fs)
                res.push_back(start);
        }
        
        
        return res;
    }
};