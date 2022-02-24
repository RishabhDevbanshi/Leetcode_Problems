class Solution {
    vector<vector<int>> dp;
    int ans = 0;
    
    int recur(vector<int> &a,vector<int> &b,int i=0,int j=0)
    {
        if(i == size(a) || j == size(b))
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        recur(a,b,i+1,j);
        recur(a,b,i,j+1);
        
        int val = a[i] == b[j] ? 1 + recur(a,b,i+1,j+1) : 0;
        ans = max(ans,val);
        
        return dp[i][j] = val;
    }
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(size(nums1),vector<int>(size(nums2),-1));
        ans = 0;
        recur(nums1,nums2);
        
        return ans;
    }
};