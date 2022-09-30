class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
         multiset<int,greater<int>> st;
        st.insert(0);
        vector<vector<int>> res;
        
        vector<pair<int,int>> arr;
        
        for(auto &ele : buildings)
        {
            arr.push_back({ele[0],-ele[2]});
            arr.push_back({ele[1],ele[2]});
        }
        
        sort(arr.begin(),arr.end());
        
        int prev = 0;
        for(auto &[x,h] : arr)
        {
            if(h<=0)
                st.insert(-h);
            else
            {
                assert(size(st) > 0);
                st.erase(st.find(h));
            }
            // prev = *st.begin();
            if(prev != *st.begin())
            {
                assert(size(st) > 0);
                res.push_back({x,*st.begin()});
            }
            prev = *st.begin();
        }
        
        return res;
    }
};