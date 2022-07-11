class Solution {
public:
    int totalStrength(vector<int>& strength) {
        const int mod = 1e9 + 7;
        stack<int> st;
        int n = size(strength);
        vector<pair<int,int>> arr(n);
        
        vector<long> pre(n+1,0) , ppre(n+2,0);
        
        for(int i=0;i<n;i++)
            pre[i+1] = (pre[i] + strength[i])%mod;
        
        for(int i=0;i<=n;i++)
            ppre[i+1] = (ppre[i] + pre[i])%mod;
        
        //on left
        arr[0].first = -1;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() and strength[st.top()] > strength[i])
                st.pop();
            arr[i].first = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        //on right
        arr.back().second = n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() and strength[st.top()] >= strength[i])
                st.pop();
            arr[i].second = st.empty() ? n : st.top();
            st.push(i);
        }
        
        //calculate
        int tot=0;
        for(int i=0;i<n;i++)
        {
            long pos = (ppre[arr[i].second + 1] - ppre[i+1]) * (i - arr[i].first);
            long neg = (ppre[i+1] - ppre[arr[i].first + 1]) * (arr[i].second - i);
            
            long val = (pos - neg + 2*mod)%mod;
            val = (val * strength[i])%mod;
            tot = (tot%mod + val%mod)%mod;
        }
        
        return tot;
    }
};