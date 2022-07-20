class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<size(s);i++)
            mp[s[i]].push_back(i);
        
        int tot=0;
        
        for(auto &word : words)
        {
            int prev = -1;
            bool ok = true;
            for(auto &ch : word)
            {
                auto it = upper_bound(mp[ch].begin(),mp[ch].end(),prev);
                if(it == mp[ch].end())
                {
                    ok = false;
                    break;
                }
                else
                    prev = *it;
            }
            tot += ok;
        }
        
        return tot;
    }
};