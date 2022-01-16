class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        set<int> st;
        for(int i=0;i<size(seats);i++) if(seats[i]) st.insert(i);
        
        int last = -1 , res = 0;
        
        for(int i=0;i<size(seats);i++)
        {
            if(seats[i]) last = i;
            else {
                int prev = INT_MAX,next = INT_MAX;
                if(last != -1) prev = i - last;
                auto it = st.upper_bound(i);
                if(it != st.end())
                {
                    next = (*it) - i;
                }
                // cout<<last<<" "<<next<<" "<<i<<"\n";
                res = max(res,min(prev,next));
            }
        }
        
        return res;
    }
};