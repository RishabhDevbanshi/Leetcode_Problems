class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto &ch : s)
        {
            mp[ch]++;
        }
        
        set<pair<int,char>,greater<pair<int,char>>> st;
        
        for(auto it : mp)
        {
            st.insert({it.second , it.first});
        }
        
        string res = "";
        while(!st.empty())
        {
            auto p = *st.begin();
            int freq = p.first;
            char ch = p.second;
            st.erase(st.begin());
            while(freq--)
                res += ch;
        }
        
        
        return res;
    }
};