class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = nums.front(), cnt = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != cand) cnt--;
            else cnt++;
            
            if(cnt == 0) cand = nums[i] , cnt = 1;
        }
        
        return cand;
    }
};