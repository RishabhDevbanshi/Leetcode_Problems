class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool ok = true, ko = true;
        int n = nums.size();
        
        if(n == 1) return;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] < nums[i-1]) ok = false;
            if(nums[i] > nums[i-1]) ko = false;
        }
        
        if(ok)
        {
            swap(nums[n-1],nums[n-2]);
            return;
        }
        if(ko)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int idx = n-1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1]) {idx = i; break;}
        }
        
        int u = idx+1;
        for(int i=n-1;i>=idx+1;i--)
        {
            if(nums[idx] < nums[i]) u = nums[u] > nums[i] ? i : u;
        }
        
        swap(nums[u],nums[idx]);
        
        // for(int ele : nums) cout<<ele<<" ";
        
        sort(nums.begin() + idx + 1,nums.end());
    }
};