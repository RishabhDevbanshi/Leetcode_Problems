class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> mp;
        int i=0 , j=0, n=s.size(), cnt=0;
        while(i<n and j<n)
        {
            // cout<<i<<" "<<j<<"\n";//
            // for(auto x : mp) cout<<x.first<<" "<<x.second<<"\n";
            // cout<<"\n";
            
            if(mp.find(s[j]) == mp.end() or mp[s[j]] == j)
            {
                mp[s[j]] = j; j++;
                cnt = max(cnt,j-i);
            }
            else
            {
                i = max(i,mp[s[j]]+1);
                mp[s[j]] = j; 
            }
        }
        
        return cnt;
    }
};