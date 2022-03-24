class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> st(people.begin(),people.end());
        
        int boats = 0;
        
        while(!st.empty())
        {
            int val = *st.begin();
            st.erase(st.begin());
            
            boats++;
            
            if(st.empty())
                break;
            
            int req = limit - val;
            
            if(*st.begin() > req)
            {
                continue;
            }
            
            auto it = st.lower_bound(req);
            
            if(it == st.end())
            {
                it--;
                st.erase(it);
            }
            else if(*it == req)
            {
                st.erase(it);
            }
            else
            {
                it--;
                st.erase(it);
            }
        }
        
        
        return boats;
    }
};