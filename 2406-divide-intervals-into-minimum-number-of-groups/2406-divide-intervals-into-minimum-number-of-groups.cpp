class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto &a,auto &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });   
        
        int cnt=0;
        multiset<int> st;
        
        for(auto &v : intervals)
        {
            // cout << v[0] << " " << v[1] << "\n";
            if(size(st))
            {
                auto it = st.lower_bound(v[0]);
                // if(it == st.end())
                // {
                //     st.insert(v[1]);
                //     // st.insert(v[1]);
                //     cnt = max<int>(cnt,size(st));
                //     continue;
                // }
                if(it == st.begin())
                {
                    st.insert(v[1]);
                    cnt = max<int>(cnt,size(st));
                    continue;
                }
                --it;
                if(it != st.end()) st.erase(it); 
                st.insert(v[1]); 
                // cout << "set -> ";
                // for(auto &val : st) cout << val << " ";
                // cout << "\n";
            }
            else st.insert(v[1]);
            cnt = max<int>(cnt,size(st));
        }
        // st.insert(v[1]);
                    cnt = max<int>(cnt,size(st));
        
        return cnt;
        
    }
};