class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        if(k == 0)
        {
            int cnt = 0;
            unordered_map<int,int> mp;
            for(auto &val : nums) mp[val]++;
            
            for(auto &[key,val] : mp)
                cnt += val>1;
            
            return cnt;
        }
        
        unordered_set<int> st;
        int cnt = 0;
        
        for(auto &val : nums)
        {
            if(st.count(val))
                continue;
            int a = val - k;
            int b = val + k;
            
            if(a==b)
            {
                cnt += st.count(a);
            }
            else
            {
                cnt += st.count(a);
                cnt += st.count(b);
            }
            
            st.insert(val);
        }
        
        
        return cnt;
    }
};