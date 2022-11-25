class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<pair<int,int>> v(size(arr));
        stack<int> st;
        
        //smallest element on left
        v[0].first = -1;
        st.push(0);
        for(int i=1;i<size(arr);i++)
        {
            while(!st.empty() and arr[st.top()] > arr[i])
                st.pop();
            v[i].first = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        //strictly smallest element on right
        v.back().second = size(arr);
        st.push(size(arr)-1);
        for(int i=size(arr)-2;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            v[i].second = st.empty() ? size(arr) : st.top();
            st.push(i);
        }
        
        //calculate
        const int mod = 1e9 + 7;
        int tot=0;
        for(int i=0;i<size(arr);i++)
        {
            int left = i - v[i].first;
            int right = v[i].second - i;
            int val = (1LL * left * right * arr[i])%mod;
            tot = (tot%mod + val%mod)%mod;
        }
        
        return tot;
    }
};