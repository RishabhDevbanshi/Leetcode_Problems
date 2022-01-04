class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int pr = 1;
        queue<int> q;
        int cnt = 0;
        
        for(int i=0;i<size(nums);i++)
        {
            while(!q.empty() and pr*nums[i] >= k)
            {
                pr /= q.front();
                q.pop();
            }
            
            if(pr*nums[i] < k)
            {
                q.push(nums[i]);
                pr *= nums[i];
                cnt += size(q);
            }
            
        }
        
        
        return cnt;
    }
};