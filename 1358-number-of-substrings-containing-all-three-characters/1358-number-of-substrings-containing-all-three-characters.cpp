class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int tot = 0;
        
        vector<int> cnt(3);
        
        for(int right=0;right<size(s);right++)
        {
            cnt[s[right] - 'a']++;
            while(cnt[0] and cnt[1] and cnt[2])
                cnt[s[left]-'a']-- , left++;
            tot += left;
        }
        
        return tot;
    }
};