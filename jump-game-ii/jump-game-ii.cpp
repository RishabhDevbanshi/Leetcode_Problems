class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumps(n,1e4);
        jumps[n-1] = 0;
        for(int i=n-2;i>=0;i--)
        {
            int val = nums[i];
            int idx = 1;
            while(idx<=val and idx+i < n) 
            {
                jumps[i] = min(jumps[i],jumps[idx+i] + 1);
                idx++;
            }
            // cout<<jumps[i]<<" ";
        }
        
        return jumps[0];
    }
};