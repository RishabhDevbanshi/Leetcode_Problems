class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        
        //no. of intervals
        int k = n-1;
        int bmin[k], bmax[k];
        for(int i=0;i<k;i++) bmin[i]=INT_MAX,bmax[i]=-1;
        
        //Average Interval
        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());
        int avgInter = ceil((double)(mx - mn)/k);
        
        //placing the elements in respective buckets
        for(int i=0;i<n;i++)
        {
            if(nums[i]==mn or nums[i]==mx) continue;
            int idx = (nums[i] - mn)/avgInter;
            bmin[idx] = min(bmin[idx],nums[i]);
            bmax[idx] = max(bmax[idx],nums[i]);
        }
        
        //calculating our ans
        int res = 0, prev = mn;
        
        for(int i=0;i<k;i++)
        {
            if(bmax[i] == -1) continue;
            res = max(res,bmin[i] - prev);
            prev = bmax[i];
        }
        
        res = max(res,mx-prev);
        
        return res;
    }
};