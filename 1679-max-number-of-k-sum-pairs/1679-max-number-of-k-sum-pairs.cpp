class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        multiset<int> st(nums.begin(),nums.end());
        
        int cnt = 0;
        
        for(auto &val : nums)
        {
            if(st.find(val) == st.end())
                continue;
            st.erase(st.find(val));
            if(st.find(k - val) != st.end())
            {
                st.erase(st.find(k - val));
                cnt++;
            }
        }
        
        return cnt;
    }
};