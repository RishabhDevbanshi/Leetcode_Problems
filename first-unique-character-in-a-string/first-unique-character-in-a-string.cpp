class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
		    queue<pair<char,int>> q;
		    string res;
            int idx = 0;
		    for(auto ch : s)
		    {
		        mp[ch]++;
		        if(mp[ch] == 1) q.push({ch,idx});
		        while(!q.empty() and mp[q.front().first] > 1) q.pop();
                idx++;
		    }
		    
		    return q.empty() ? -1 : q.front().second;
    }
};