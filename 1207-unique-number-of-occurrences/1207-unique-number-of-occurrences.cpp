class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> st;
        unordered_map<int,int> mp;
        for(auto &ele : arr)
        {
            mp[ele]++;
        }
        
        for(auto &[key,value] : mp)
        {
            if(st.count(value))
                return false;
            else st.insert(value);
        }
        
        return true;
    }
};