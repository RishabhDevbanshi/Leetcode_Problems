class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++) st.insert(nums[i]);
        
        int ans = 0;
        
        for(int ele : nums)
        {
            if(st.find(ele) == st.end()) continue;
            int prev = ele - 1;
            int next = ele + 1;
            bool ok = true;
            int cnt = 1; 
            st.erase(ele);
            while(ok)
            {
                ok = false;
                if(st.find(prev) != st.end())
                {
                    ok = true;
                    st.erase(prev);
                    prev--;
                    cnt++;
                }
                
                if(st.find(next) != st.end())
                {
                    ok = true;
                    st.erase(next);
                    next++;
                    cnt++;
                }
            }
            
            ans = max(ans,cnt);
        }
        
        return ans;
        
    }
};