class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<size(s);i++)
            mp[s[i]] = i;
        
        vector<int> ans;
        
        int curr = 0 , prev = 0;
        
        for(int i=0;i<size(s);i++)
        {
            curr = max(curr,mp[s[i]]);
            if(i == curr)
            {
                ans.push_back(curr - prev + 1);
                prev = i+1;
                curr = i;
            }
            else
            {
                curr = max(curr,mp[s[i]]);
            }
        }
        
        
        return ans;
    }
};