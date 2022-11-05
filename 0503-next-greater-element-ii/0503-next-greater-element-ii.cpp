class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = size(nums);
        auto f = [&](vector<int> &arr){
            stack<int> st;
            vector<int> ng(size(arr),-1);
            for(int i=size(arr)-1;i>=0;i--)
            {
                while(!st.empty() and arr[st.top()] <= arr[i])
                    st.pop();
                if(!st.empty())
                    ng[i] = arr[st.top()];
                st.push(i);
            }
            
            vector<int> res;
            for(int i=0;i<n;i++)
                res.push_back(ng[i]);
            
            return res;
        };
        
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        
        return f(nums);
        
    }
};