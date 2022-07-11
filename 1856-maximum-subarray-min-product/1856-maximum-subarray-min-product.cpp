class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int mod = 1e9 + 7;
        stack<int> st;
        vector<pair<int,int>> arr(size(nums));
        
        //calculate prefix
        vector<long> pre(size(nums)+1);
        for(int i=0;i<size(nums);i++)
            pre[i+1] = (pre[i] + nums[i]);
        
        //on left
        arr[0].first = -1;
        st.push(0);
        for(int i=1;i<size(nums);i++)
        {
            while(!st.empty() and nums[st.top()] > nums[i])
                st.pop();
            arr[i].first = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        //on right
        arr.back().second = size(nums);
        st.push(size(nums)-1);
        for(int i=size(nums)-2;i>=0;i--)
        {
            while(!st.empty() and nums[st.top()] >= nums[i])
                st.pop();
            arr[i].second = st.empty() ? size(nums) : st.top();
            st.push(i);
        }
        
        long maxi = 0;
        for(int i=0;i<size(nums);i++)
        {
            long sum = pre[arr[i].second] - pre[arr[i].first + 1];
            long val = (1LL * sum * nums[i]);
            maxi = max(maxi,val);
        }
        
        
        return maxi%mod;
    }
};