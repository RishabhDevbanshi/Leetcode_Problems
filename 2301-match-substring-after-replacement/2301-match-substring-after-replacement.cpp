class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char,unordered_set<char>> mp;
        for(auto &v : mappings)
            mp[v[0]].insert(v[1]);
        
        for(int i=0;i<size(s);i++)
        {
            int j=0 , k=i;
            while(j<size(sub) and k<size(s))
            {
                if(sub[j] == s[k] || mp[sub[j]].find(s[k]) != mp[sub[j]].end())
                    k++ , j++;
                else
                {
                    break;
                }
            }
            
            if(j == size(sub))
                return true;
        }
        
        return false;
    }
};