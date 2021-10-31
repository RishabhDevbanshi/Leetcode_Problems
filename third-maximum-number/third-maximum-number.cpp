class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int,greater<int>> st;
        for(auto val : nums) st.insert(val);
        int idx = 0;
        for(auto &ele : st)
        {
            if(idx == 2) return ele;
            idx++;
        }
        
        return *st.begin();
    }
};