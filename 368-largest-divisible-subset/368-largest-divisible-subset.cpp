class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(size(nums),1) , par(size(nums),-1) , res;
        
        int maxi = 0 , midx = 0;
        
        for(int i=0;i<size(nums);i++)
        {
            int len =0  ,idx = -1;
            for(int j=0;j<=i-1;j++)
            {
                if(nums[i]%nums[j] == 0 and len < dp[j])
                    len = dp[j] , idx = j;
            }
            dp[i] += len , par[i] = idx;
            if(dp[i] > maxi) maxi = dp[i] , midx = i;
        }
        
        // for(auto &val : par) cout << val << " ";
        // cout << endl;
        
        while(midx != -1)
        {
            res.push_back(nums[midx]);
            midx = par[midx];
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};