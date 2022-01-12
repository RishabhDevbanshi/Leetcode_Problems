class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_multiset st(t.begin(),t.end());
        
        for(auto &ch : s)
        {
            st.erase(st.find(ch));
        }
        
        assert(size(st) == 1);
        return *st.begin();
    }
};