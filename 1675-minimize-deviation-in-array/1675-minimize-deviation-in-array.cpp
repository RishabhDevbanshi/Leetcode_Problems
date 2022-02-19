class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        
        int mini = INT_MAX;
        
        for(auto &val : nums)
        {
            val = val&1 ? (val<<1) : val;
            pq.push(val);
            mini = min(mini,val);
        }
        
        int res = INT_MAX;
        
        while(!(pq.top()&1))
        {
            int val = pq.top();
            pq.pop();
            res = min(res,val - mini);
            mini = min(mini,val>>1);
            pq.push(val>>1);
        }
        
        res = min(res,pq.top()-mini);
        
        return res;
    }
};