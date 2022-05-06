class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>  st;
        
        for(auto &val : s)
        {
            if(st.empty())
                st.push({val,1});
            else
            {
                if(st.top().first == val)
                {
                    st.push({val,st.top().second + 1});
                    if(st.top().second == k)
                    {
                        while(!st.empty() and st.top().first == val)
                            st.pop();
                    }
                }
                else
                    st.push({val,1});
            }
        }
     
        s = "";
        while(!st.empty())
            s += st.top().first , st.pop();
        
        reverse(s.begin(),s.end());
        return s;
    }
};