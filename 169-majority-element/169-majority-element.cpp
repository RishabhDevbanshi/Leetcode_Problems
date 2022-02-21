class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = nums[0] , cnt = 0;
        for(auto &val : nums)
        {
            if(val == cand) cnt++;
            else cnt--;
            
            if(cnt == 0) cand = val , cnt = 1;
        }
        
        
        return cand;
    }
};