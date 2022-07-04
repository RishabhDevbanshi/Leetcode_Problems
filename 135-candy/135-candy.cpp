class Solution {
public:
    int candy(vector<int>& ratings) {
        set<pair<int,int>> st;
        for(int i=0;i<size(ratings);i++)
        {
            st.insert({ratings[i],i});
        }
        
        vector<int> candy(size(ratings));
        int tot = 0;
        
        while(!st.empty())
        {
            auto [val,idx] = *st.begin(); st.erase(st.begin());
            int maxi = 0;
            if(idx>0 and ratings[idx-1] < ratings[idx]) maxi = candy[idx-1];
            if(idx+1<size(ratings) and ratings[idx+1] < ratings[idx]) maxi = max(maxi,candy[idx+1]);
            candy[idx] = maxi+1 , tot += maxi+1;
        }
        
        return tot;
    }
};