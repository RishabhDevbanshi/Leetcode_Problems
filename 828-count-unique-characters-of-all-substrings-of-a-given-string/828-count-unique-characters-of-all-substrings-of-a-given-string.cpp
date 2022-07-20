class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char,vector<int>> mp;
        
        for(int i=0;i<size(s);i++)
            mp[s[i]].push_back(i);
        
        vector<pair<int,int>> arr(size(s));
        
        for(auto it : mp)
        {
            int n = size(it.second);
            
            for(int i=0;i<n;i++)
            {
                //for left
                if(i == 0)
                    arr[it.second[i]].first = -1;
                else
                    arr[it.second[i]].first = it.second[i-1];
                
                //for right
                if(i == n-1)
                    arr[it.second[i]].second = size(s);
                else
                    arr[it.second[i]].second = it.second[i+1];
            }
        }
        
        int tot=0;
        for(int i=0;i<size(arr);i++)
        {
            tot += (i - arr[i].first) * (arr[i].second - i);
        }
        
        return tot;
    }
};