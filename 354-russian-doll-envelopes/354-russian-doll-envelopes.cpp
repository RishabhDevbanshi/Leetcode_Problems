class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[&](auto &a,auto &b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        
        vector<int> lis;
        
        for(auto &val : envelopes)
        {
            auto it = lower_bound(lis.begin(),lis.end(),val[1]) - lis.begin();
            if(it >= size(lis))
                lis.push_back(val[1]);
            else
                lis[it] = val[1];
        }
        
        return size(lis);
    }
};