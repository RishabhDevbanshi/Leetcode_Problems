class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sa(26,0) , pa(26,0) , res;
        if(size(s) < size(p))
            return res;
        
        for(int i=0;i<size(p);i++)
        {
            sa[s[i]-'a']++;
            pa[p[i]-'a']++;
        }
        
        int back = 0;
        
        if(sa == pa)
            res.push_back(back);
        
        
        for(int i=size(p);i<size(s);i++)
        {
            sa[s[back++]-'a']--;
            sa[s[i]-'a']++;
            
            if(sa == pa)
                res.push_back(back);
        }
        
        return res;
        
    }
};