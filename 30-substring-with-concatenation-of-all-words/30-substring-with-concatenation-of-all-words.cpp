class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int winSize = size(words) * size(words[0]);
        
        if(size(s) < winSize)
            return {};
        
        unordered_map<string,int> mp;
        for(auto &word : words)
            mp[word]++;
        
        vector<int> res;
        
        int i = 0 , j = winSize - 1;
        while(j<size(s))
        {
            unordered_map<string,int> tmp;
            
            int k = i;
            while(k<=j)
            {
                string word = s.substr(k,size(words[0]));
                tmp[word]++;
                k += size(words[0]);
            }
            
            if(tmp == mp)
                res.push_back(i);
            i++ , j++;
        }
        
        return res;
    }
};