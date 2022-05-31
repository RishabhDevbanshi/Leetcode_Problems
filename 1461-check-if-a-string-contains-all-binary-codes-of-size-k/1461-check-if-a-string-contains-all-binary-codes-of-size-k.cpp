class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        unordered_set<string> st;
        for(int i=0;i<=max<int>(0,size(s)-k);i++)
            st.insert(s.substr(i,k));
        
        return size(st) == (1LL<<k);
    }
};