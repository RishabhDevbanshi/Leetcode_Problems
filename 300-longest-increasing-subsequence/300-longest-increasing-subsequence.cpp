class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        for(auto &val : nums)
        {
            auto it = lower_bound(arr.begin(),arr.end(),val) - arr.begin();
            if(it == size(arr))
                arr.push_back(val);
            else
                arr[it] = val;
        }
        
        return size(arr);
    }
};