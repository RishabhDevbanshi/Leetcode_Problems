class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> st;
        
        int mini = nums[0];
        st.push({nums[0],mini});
        
        for(int i=1;i<size(nums);i++)
        {
            while(!st.empty() and st.top().first <= nums[i])
                st.pop();
            if(!st.empty() and st.top().first > nums[i] 
                        and st.top().second < nums[i])
                return true;
            
            st.push({nums[i],mini});
            mini = min(mini,nums[i]);
        }
        
        return false;
    }
};