class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int doub = 0, cnt=0;
        
        unordered_map<string,int> mp;
        
        for(auto &word : words)
        {
            string rev = "";
            rev += word[1];
            rev += word[0]; 
            if(mp.find(rev) != mp.end() and mp[rev])
                mp[rev]-- , cnt++;
            else
                mp[word]++;
        }
        
        for(auto &it : mp)
        {
            if(it.second == 0)
                continue;
            if(it.first[0] == it.first[1])
            {
                doub++;
                break;
            }
        }
        
        return (4*cnt) + (2*doub);
    }
};