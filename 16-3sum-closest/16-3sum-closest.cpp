class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff=INT_MAX,res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size(nums);i++)
        {
            int start = i+1 , end = size(nums)-1;
            while(start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target)
                    return target;
                int curr = abs(sum - target);
                // cout << sum << " ";
                if(curr < diff)
                    diff = curr , res = sum;
                if(sum > target) end--;
                else start++;
            }
        }
        
        return res;
    }
};