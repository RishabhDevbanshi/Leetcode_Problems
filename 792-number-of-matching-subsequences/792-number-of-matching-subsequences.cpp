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
                bool flag = false;
                for(auto &idx : mp[ch])
                {
                    if(idx > prev)
                    {
                        prev = idx;
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    ok = false;
                    break;
                }
            }
            tot += ok;
        }
        
        return tot;
    }
};