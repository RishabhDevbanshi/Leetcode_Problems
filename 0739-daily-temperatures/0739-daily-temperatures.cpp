class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n,0);
        stack<int> st;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() and temp[st.top()] <= temp[i])
            {
                st.pop();
            }
            
            res[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        
        return res;
    }
};