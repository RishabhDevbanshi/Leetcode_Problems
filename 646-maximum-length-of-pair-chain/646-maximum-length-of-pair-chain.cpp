class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[&](auto a,auto b){
            return a[1] < b[1];
        });
        
        int prev = pairs[0][1];
        
        int cnt=1;
        
        for(auto &pair : pairs)
        {
            if(pair[0] > prev)
                cnt++ , prev = pair[1];
        }
        
        return cnt;
    }
};