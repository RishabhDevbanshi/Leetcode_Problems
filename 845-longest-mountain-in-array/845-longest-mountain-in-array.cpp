class Solution {
public:
    int longestMountain(vector<int>& nums) {
        
        vector<int> inc(size(nums)) , dec(size(nums));
        int n = size(nums), cnt = 0;
        
        // cnt = 1;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] > nums[i-1]) cnt++;
            else cnt = 0;
            
            inc[i] = cnt;
        }
        
        cnt = 0;
        
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1]) cnt++;
            else cnt = 0;
            
            dec[i] = cnt;
        }
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            // cout<<inc[i]<<" "<<dec[i]<<"\n";
            if(dec[i] == 0 || inc[i] == 0) res = max(res,0);
            else res = max(res,inc[i] + dec[i] + 1);
        }
        
        return res;
        
    }
};