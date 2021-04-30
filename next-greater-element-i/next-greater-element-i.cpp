class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n);
        dp[n-1] = -1;
        stack<int> st;
        map<int,int> mp;
        mp[arr[n-1]] = n-1;
        st.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            mp[arr[i]] = i;
            while(!st.empty())
            {
                int node = st.top();
                if(node > arr[i]) {dp[i] = node; break;}
                else st.pop();
            }
            
            if(st.empty()) dp[i] = -1;
            st.push(arr[i]);
        }
        
        // for(auto x : dp) cout<<x<<" ";
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            ans[i] = dp[mp[nums[i]]];
        }
        
        return ans;
    }
};