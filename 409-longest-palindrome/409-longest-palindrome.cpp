class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto &ch : s)
            mp[ch]++;
        int ans = 0;
        
        bool ok = false;
        for(auto it : mp)
        {
            int a = it.second;
            ans += (a/2);
            a %= 2;
            ok |= a > 0;
        }
        
        ans *= 2;
        if(ok)
            ans++;
        
        return ans;
    }
};