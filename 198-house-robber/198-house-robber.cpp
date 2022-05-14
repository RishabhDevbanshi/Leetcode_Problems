class Solution {
public:
    int rob(vector<int>& nums) {
        int in = nums.front(), ex = 0;
        
        for(int i=1;i<nums.size();i++)
        {
            int nin = ex + nums[i];
            int nex = max(ex,in);
            
            in = nin , ex = nex;
        }
        
        return max(in,ex);
    }
};