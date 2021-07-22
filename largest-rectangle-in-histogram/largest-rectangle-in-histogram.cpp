#define ll int
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        ll rb[n] , lb[n];
        stack<ll> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty()) lb[i] = 0;
            else lb[i] = st.top() + 1;
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty()) rb[i] = n-1;
            else rb[i] = st.top() - 1;
            st.push(i);
        }
        
        ll res = 0;
        
        for(int i=0;i<n;i++)
        {
            ll area = arr[i] * (rb[i] - lb[i] + 1);
            res = max(res,area);
        }
        
        return res;
    }
};