class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long> pre(size(nums));
        
        pre[0] = nums[0];
        for(int i=1;i<size(nums);i++)
            pre[i] = pre[i-1] + nums[i];
        
        vector<long> suf(size(nums));
        suf.back() = nums.back();
        
        for(int i=size(nums)-2;i>=0;i--)
            suf[i] = suf[i+1] + nums[i];
        
        long mini = 1e8;
        
        int n = size(nums);
        
        int idx = -1;
        
        for(int i=0;i<size(nums);i++)
        {
            long f = pre[i]/(i+1);
            long s = i+1 < n ? suf[i+1]/(n-i-1) : 0;
            
            
            if(abs(f-s) < mini)
            {
                mini = abs(f-s); idx = i;
            }
            // mini = min(mini,abs(f-s));
        }
        
        return idx;
    }
};