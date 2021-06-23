class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<int> st;
        int i=0 , j=0, n=s.size();
        int cnt = 0;
        
        while(i<n and j<n)
        {
            if(st.find(s[j]) != st.end())
            {
                st.erase(s[i++]);
            }
            else
            {
                st.insert(s[j++]);
                cnt = max(cnt,j-i);
            }
        }
        
        return cnt;
    }
};