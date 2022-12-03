class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> arr(2);
        
        map<int,int> mp;
        
        for(auto &match : matches)
        {
            mp[match[1]]++;
            if(mp.find(match[0]) == mp.end())
                mp[match[0]] = 0;
        }
        
        for(auto &it : mp)
        {
            if(it.second == 0)
                arr[0].push_back(it.first);
            else if(it.second == 1)
                arr[1].push_back(it.first);
        }
        
        // sort(arr[0].begin(),arr[0].begin());
        // sort(arr[1].begin(),arr[1].begin());
        
        return arr;
    }
};