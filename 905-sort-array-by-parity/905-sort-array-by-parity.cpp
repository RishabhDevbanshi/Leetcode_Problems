class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        deque<int> q;
        for(auto &val : nums)
        {
            if(val&1) q.push_back(val);
            else q.push_front(val);
        }
        
        int i = 0;
        
        while(!q.empty())
        {
            int val = q.front();
            q.pop_front();
            
            nums[i++] = val;
        }
        
        return nums;
    }
};