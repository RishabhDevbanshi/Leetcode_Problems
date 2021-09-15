class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0;
        int n = nums.size();
        vector<int> res;
        while(i<k)
        {
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            // res[i] = nums[dq.front()];
            i++;
        }
        
        
        res.push_back(nums[dq.front()]);
        
        while(i < n)
        {
            if(dq.front() <= i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            // res[i] = nums[dq.front()];
            res.push_back(nums[dq.front()]);
            i++;
        }
        
        
        return res;
    }
};