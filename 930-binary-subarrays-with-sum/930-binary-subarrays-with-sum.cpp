class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        auto atMost = [&](int sum){
            int i = 0;
            int tot = 0;
            int curr = 0;
            for(int j=0;j<size(nums);j++)
            {
                curr += nums[j];
                while(i<=j and curr > sum)
                    curr -= nums[i++];
                tot += j - i + 1;
            }
            
            return tot;
        };
        
        return atMost(goal) - atMost(goal-1);
    }
};