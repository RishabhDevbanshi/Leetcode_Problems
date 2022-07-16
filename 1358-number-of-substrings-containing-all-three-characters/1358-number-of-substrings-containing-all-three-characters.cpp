class Solution {
public:
    int numberOfSubstrings(string s) {
        
        auto atMost = [&](int k){
            int left=0 , tot=0;
            vector<int> cnt(3);
            for(int right=0;right<size(s);right++)
            {
                cnt[s[right]-'a']++;
                while((cnt[0]>0) + (cnt[1]>0) + (cnt[2]>0) > k)
                   cnt[s[left] - 'a']-- , left++;
                tot += (right - left + 1);
            }
            
            return tot;
        };
        
        long n = size(s);
        long all = (n * (n+1))/2;
        
        return all - atMost(2);
    }
};