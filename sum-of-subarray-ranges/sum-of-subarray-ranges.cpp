class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        typedef long long ll;
        ll n = size(nums);
        ll res = 0;        
        
        for(int i=0;i<n;i++)
        {
            ll mn = nums[i] , mx = nums[i];
            for(int j=i+1;j<n;j++)
            {
                if(nums[j] > mx) mx = nums[j];
                if(nums[j] < mn) mn = nums[j];
                
                res += (mx - mn);
            }
        }
        
        return res;
    }
};