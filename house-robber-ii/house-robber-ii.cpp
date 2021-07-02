class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int inc = nums[0],exc = 0;
        int n = nums.size();
        
        //finding max sum from 0 to n-1
        for(int i=1;i<n-1;i++)
        {
            int ninc = exc + nums[i];
            int nexc = max(inc,exc);
            inc = ninc;
            exc = nexc;
        }
        
        int ans1 = max(inc,exc);
        
        if(nums.size() < 2) return ans1;
        
        inc = nums[1],exc=0;
        
        //finding max sum from 1 to n
        for(int i=2;i<n;i++)
        {
            int ninc = exc + nums[i];
            int nexc = max(inc,exc);
            inc = ninc;
            exc = nexc;
        }
        
        int ans2 = max(inc,exc);
        
        int ans = max(ans1,ans2);
        
        return ans;
    }
};