class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        for(int i=0;i<size(nums);i++)
        {
            if(st.empty() or nums[st.top()] > nums[i])
                st.push(i);
        }
        
        int maxi = 0;
        
        for(int i=size(nums)-1;i>=0;i--)
        {
            while(!st.empty() and nums[st.top()] <= nums[i])
            {
                maxi = max(maxi,i - st.top()) ;
                // cout << i << " " << st.top() << "\n";
                st.pop();
            }
        }
        
        return maxi;
    }
};