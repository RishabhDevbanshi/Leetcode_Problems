class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = size(nums);
        
        vector<int> segTree(4*n,INT_MIN);
        
        function<int(int,int,int,int,int)> query = [&](int l,int r,int seg_idx,int start,int end){
            if(start > r || end < l)
                return INT_MIN;
            if(start<=l and r<=end)
                return segTree[seg_idx];
            
            int mid = (l + r)>>1;
            
            int left_ans = query(l,mid,2*seg_idx + 1,start,end);
            int right_ans = query(mid+1,r,2*seg_idx + 2,start,end);
            
            
            return max(left_ans,right_ans);
        };
        
        function<void(int,int,int,int,int)> update = [&](int l,int r,int seg_idx,int idx,int val){
            
            if(l == r)
            {
                segTree[seg_idx] = max(segTree[seg_idx],val);
                return;
            }
            
            int mid = (l + r)>>1;
            if(l<=idx and idx<=mid)
                update(l,mid,2*seg_idx + 1,idx,val);
            if(mid+1<=idx and idx<=r)
                update(mid+1,r,2*seg_idx + 2,idx,val);
            
            segTree[seg_idx] = max(segTree[2*seg_idx + 1] , segTree[2*seg_idx + 2]);
        };
        
        int dp[n];
        dp[n-1] = nums.back();
        
        update(0,n-1,0,n-1,dp[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            int start = min(i+1,n-1) , end = min(i+k,n-1);
            int val = query(0,n-1,0,start,end);
            
            dp[i] = val == INT_MIN ? val : val + nums[i];
            update(0,n-1,0,i,dp[i]);
        }
        
        return dp[0];
    }
};