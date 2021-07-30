#define ll long long

class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        vector<ll> nums(arr.begin(),arr.end());
        bool hasN = false;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == n) hasN = true;
            if(nums[i] <= 0 or nums[i] >= n) nums[i] = 0;
        }
        
        for(int i=0;i<n;i++)
        {
            ll val = nums[i]%n;
            if(val == 0 or nums[val]/n == val) { continue;}
            nums[val] += val * n;
        }
        // for(int i=0;i<n;i++) cout<<nums[i]<<" ";
        
        for(int i=1;i<n;i++) 
        {
            if(i != nums[i]/n)
                return i;
        }
        
        return hasN?n+1:n;
    }
};