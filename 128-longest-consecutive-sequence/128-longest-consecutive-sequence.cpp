class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        
        int maxi = 0;
        
        while(!st.empty())
        {
            int val = *st.begin(); st.erase(st.begin());
            int prev = val-1;
            int cnt = 1;
            
            while(st.find(prev) != st.end())
                st.erase(prev) , cnt++ , prev--;
            
            int next = val + 1;
            while(st.find(next) != st.end())
                st.erase(next) , cnt++ , next++;
            
            maxi = max(maxi,cnt);
        }
        
        return maxi;
    }
};