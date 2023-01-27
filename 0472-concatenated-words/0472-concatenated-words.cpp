class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_map<string,int> mp;
        for(auto &word : words)
            mp[word]++;
        
        string curr = "";
        vector<int> dp(31,-1);
        
        function<bool(int)> dfs = [&](int idx)->bool{
            if(idx == size(curr))
                return true;
            
            // if(dp[idx] != -1)
            //     return dp[idx];
            
            string tmp = "";
            for(int i=idx;i<size(curr);i++)
            {
                tmp += curr[i];
                if(mp.find(tmp) != mp.end() and mp[tmp] != 0)
                {
                    bool ok = dfs(i+1);
                    if(ok)
                        return dp[idx] = true;
                }
            }
            
            return dp[idx] = false;
        };
        
        vector<string> res;
        
        for(auto &word : words)
        {
            curr = word;
            mp[word]=0;
            dp.resize(31,-1);
            if(dfs(0)) 
                res.push_back(word);
            mp[word]=1;
        }
        
        return res;
    }
};