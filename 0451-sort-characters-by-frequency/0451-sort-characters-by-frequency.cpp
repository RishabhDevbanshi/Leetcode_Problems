class Solution {
public:
    string frequencySort(string s) {
        // vector<int> freq(26);
        unordered_map<char,int> mp;
        
        for(auto &ch : s)
            mp[ch]++;
        
        sort(s.begin(),s.end(),[&](auto &a,auto &b){
            if(mp[a] == mp[b])
                return a>b;
            return mp[a] > mp[b];
        });
        
        
        return s;
    }
};