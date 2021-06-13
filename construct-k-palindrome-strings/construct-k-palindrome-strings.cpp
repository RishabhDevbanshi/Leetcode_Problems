class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        else if(s.size() == k) return true;
        
        map<char,int> mp;
        for(auto ch : s) mp[ch]++;
        int odd = 0;
        for(auto ele : mp) if(mp[ele.first]&1) odd++;
        
        // cout<<odd<<"\n";
        
        if(odd > k) return false;
        
        return true;
    }
};