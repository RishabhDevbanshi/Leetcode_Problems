class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int mp[size(nums)+1];
        
        int cnt = 0;
        int zero = 0;
        for(auto &val : nums) cnt+= val == 1;
        int mx = 0;
        int i;
        for(i=0;i<size(nums);i++)
        {
            mp[i] = cnt + zero;
            mx = max(mx,mp[i]);
            int val = nums[i];
            cnt -= val == 1;
            zero += val == 0;
        }
        
        mp[i] = zero  +cnt;
        
        mx = max(mx,mp[i]);
        
        vector<int> arr;
        
        for(int i=0;i<=size(nums);i++)
        {
            if(mp[i] == mx)
            {
                arr.push_back(i);
            }
        }
        
        return arr;
    }
};