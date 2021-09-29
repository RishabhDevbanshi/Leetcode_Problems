class Solution {
public:
    int minSteps(string s, string t) {
        if(s.size() != t.size()) return -1;
        int arr[30];
        memset(arr,0,sizeof(arr));
        
        for(auto &ch : s) arr[ch - 'a']++;
        int cnt = 0;
        
        for(auto &ch : t)
        {
            arr[ch - 'a']--;
            cnt += arr[ch - 'a'] < 0;
        }
        
        return cnt;
    }
};