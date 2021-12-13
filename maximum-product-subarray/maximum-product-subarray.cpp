class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = size(nums);
        
        int mx = nums.front() , mn = nums.front() , res = nums.front();
        
        for(int i=1;i<n;i++)
        {
            int val = nums[i];
            
            if(val < 0) swap(mx,mn);
            
            mx = max(val,val*mx);
            mn = min(val,val*mn);
            
            res = max({res,mx});
        }
        
        return res;
    }
};