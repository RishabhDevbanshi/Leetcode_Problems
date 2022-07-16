class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        auto atMost = [&](int cnt){
            int left=0;
            int tot=0 , x=0;
            for(int right=0;right<size(nums);right++)
            {
                x += (nums[right]%2);
                while(left <= right and x>cnt)
                    x -= (nums[left]%2) , left++;
                tot += right - left + 1;
            }
            
            return tot;
        };
        
        return atMost(k) - atMost(k-1);
    }
};