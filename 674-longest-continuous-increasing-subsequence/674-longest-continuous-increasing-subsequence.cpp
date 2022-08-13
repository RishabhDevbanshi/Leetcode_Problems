class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxi=1,curr=1;
        for(int i=1;i<size(nums);i++)
        {
            if(nums[i] > nums[i-1])
                curr++;
            else 
                curr = 1;
            maxi = max(maxi,curr);
        }
        
        return maxi;
    }
};