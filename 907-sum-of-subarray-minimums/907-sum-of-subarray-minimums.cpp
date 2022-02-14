class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = size(arr);
        vector<int> left(n,0) , right(n,0);
        
        stack<pair<int,int>> st;
        
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            while(!st.empty() and st.top().first > arr[i])
            {
                cnt += st.top().second;
                st.pop();
            }
            
            st.push({arr[i],left[i] = 1 + cnt});
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            int cnt = 0;
            while(!st.empty() and st.top().first >= arr[i])
            {
                cnt += st.top().second;
                st.pop();
            }
            
            st.push({arr[i],right[i] = 1 + cnt});
        }
        
        long long ans = 0;
        const int mod = 1e9 + 7;
        
        for(int i=0;i<n;i++)
        {
            // cout<<left[i]<<" "<<right[i]<<"\n";
            
            ans = (ans%mod + (1LL * arr[i] * left[i] * right[i])%mod)%mod;
        }
        
        return ans;
    }
};