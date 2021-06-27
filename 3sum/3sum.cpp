class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> arr;
        if(n<3) return arr;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(i > 0 and nums[i] == nums[i-1]) continue;
            int val = -nums[i];
            int start = i+1,end=n-1;
            while(start < end)
            {
                int sum = nums[start] + nums[end];
                if(sum == val)
                {
                    vector<int> tri(3);
                    tri[0] = nums[i], tri[1] = nums[start] , tri[2] = nums[end];
                    arr.push_back(tri);
                    while(start < end and nums[start] == tri[1]) ++start;
                    while(end > start and nums[end] == tri[2]) --end;
                }
                else if(sum < val) start++;
                else end--;
            }
            
            // while(i<n-1 and nums[i] == nums[i+1]) ++i;
        }
        
        return arr;
    }
};