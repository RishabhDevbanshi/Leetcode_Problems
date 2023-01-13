class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int idx=0 , cnt=0;
        for(auto &child : g)
        {
            while(idx<size(s) and s[idx]<child)
                idx++;
            if(idx<size(s))
                idx++,cnt++;
            else
                break;
        }
        
        return cnt;
    }
};