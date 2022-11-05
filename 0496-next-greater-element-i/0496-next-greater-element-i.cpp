class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ng(size(nums2),-1);
        
        for(int i=size(nums2)-1;i>=0;i--)
        {
            while(!st.empty() and st.top() < nums2[i])
                st.pop();
            if(!st.empty())
                ng[i] = st.top();
            st.push(nums2[i]);
        }
        
        vector<int> res;
        
        for(auto &ele : nums1)
        {
            for(int i=0;i<size(nums2);i++)
            {
                if(ele == nums2[i])
                {
                    res.push_back(ng[i]);
                    break;
                }
            }
        }
        
        
        return res;
    }
};