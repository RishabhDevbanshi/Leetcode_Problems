class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        multiset<int> st(nums.begin(),nums.end());
        
        int mini = nums[0];
        
        for(auto &val : nums)
        {
            st.erase(st.find(val));
            
            if(val > mini)
            {
                auto it = st.upper_bound(mini);
                
                // if(it != st.end())
                    // cout << mini << " " << val << " " << *it << "\n";
                
                if(it == st.end() || *it >= val)
                    continue;
                
                // cout << mini << " " << *it << "\n";
                
                
                
                // cout << mini << " " << val << " " << *it << "\n";
                
                
                
                // cout << mini << " " << 
                return true;
            }
            else mini = min(mini,val);
        }
        
        return false;
    }
};