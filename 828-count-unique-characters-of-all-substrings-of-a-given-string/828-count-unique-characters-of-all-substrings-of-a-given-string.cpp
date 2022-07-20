class Solution {
public:
    int uniqueLetterString(string s) {
        
        vector<int> idx(26,-1);
        vector<pair<int,int>> arr(size(s));
        
        
        for(int i=0;i<size(s);i++)
        {
            if(idx[s[i] - 'A'] == -1)
                arr[i].first = -1;
            else
                arr[i].first = idx[s[i] - 'A'];
            idx[s[i]-'A'] = i;
        }
        
        for(auto &val : idx)
            val = -1;
        
        for(int i=size(s)-1;i>=0;i--)
        {
            if(idx[s[i] - 'A'] == -1)
                arr[i].second = size(s);
            else
                arr[i].second = idx[s[i] - 'A'];
            idx[s[i] - 'A'] = i;
        }
        
        int tot=0;
        for(int i=0;i<size(arr);i++)
        {
            tot += (i - arr[i].first) * (arr[i].second - i);
        }
        
        return tot;
    }
};