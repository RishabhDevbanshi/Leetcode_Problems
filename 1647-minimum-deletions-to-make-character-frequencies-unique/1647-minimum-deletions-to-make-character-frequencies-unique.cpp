class Solution {
public:
    int minDeletions(string s) {
        int cnt = 0;
        vector<int> freq(26);
        for(auto &ch : s)
            freq[ch - 'a']++;
        sort(freq.begin(),freq.end(),greater<int>());
        
        int maxi = freq[0];
        for(int i=1;i<26;i++)
        {
            if(freq[i] == 0)
                break;
            if(freq[i] < maxi) maxi = freq[i];
            else maxi = max(0,maxi-1) , cnt += freq[i] - maxi;
        }
        
        return cnt;
        
    }
};