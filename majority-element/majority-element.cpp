class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = nums[0] , cnt = 0;
        
        for(auto &ele : nums)
        {
            if(ele == cand) cnt++;
            else cnt--;
            
            if(cnt == 0) cand = ele , cnt = 1;
        }
        
        cnt = 0;
        
        for(auto &ele : nums)
        {
            cnt += (cand == ele);
        }
        
        return cnt > size(nums)/2 ? cand : -1;
        
    }
};