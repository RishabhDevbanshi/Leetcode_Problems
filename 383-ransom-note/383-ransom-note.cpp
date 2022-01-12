class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        multiset<char> st(magazine.begin(),magazine.end());
        
        for(auto &ch : ransomNote)
        {
            auto it = st.find(ch);
            if(it == st.end()) return false;
            else st.erase(it);
        }
        
        return true;
        
    }
};