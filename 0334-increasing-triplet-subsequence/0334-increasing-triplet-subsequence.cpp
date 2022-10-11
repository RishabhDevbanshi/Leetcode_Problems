class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> b;
        int maxi = nums.back();
        for(int i=size(nums)-1;i>=0;i--)
            b.push_back(maxi = max(maxi,nums[i]));
        
        reverse(b.begin(),b.end());
        
        int mini = nums[0];
        int idx = 0;
        for(auto &val : nums)
        {
            if(mini < val and size(b) and idx < size(nums)-1 and b[idx+1] > val)
            {
                // cout << mini << " " << val << " " << b[idx+1] << "\n";
                return true;
            }
            // a.insert(val);
            mini = min(mini,val);
            ++idx;
        }
        
        return false;
    }
};