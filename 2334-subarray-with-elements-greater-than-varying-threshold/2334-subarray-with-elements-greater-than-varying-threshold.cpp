class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        stack<int> st;
        int n = size(nums);
        vector<pair<int,int>> arr(n);
        
        //on left
        arr[0].first = -1;
        st.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(!st.empty() and nums[st.top()] > nums[i])
                st.pop();
            arr[i].first = st.empty()?  -1 : st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        //on right
        arr.back().second = n;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() and nums[st.top()] >= nums[i])
                st.pop();
            arr[i].second = st.empty() ? n : st.top();
            st.push(i);
        }
        
        for(int i=0;i<n;i++)
        {
            int sz = arr[i].second - arr[i].first - 1;
            int lim = threshold / sz;
            if(nums[i] > lim)
                return sz;
        }
        
        return -1;
    }
};