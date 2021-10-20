class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size();
        sort(strs.begin(),strs.end());
            
        string res = "";
        
        int n = min(strs[0].size() , strs[sz-1].size());
        
        for(int i=0;i<n;i++)
        {
            if(strs[0][i] != strs[sz-1][i]) break;
            
            res += strs[0][i];
        }
        
        return res;
    }
};