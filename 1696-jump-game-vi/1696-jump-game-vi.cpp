class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        typedef pair<int,int> pii;
        priority_queue<pii> pq;
        pq.push({nums.back(),size(nums)-1});
        
        int score = nums.back();
        
        for(int i=size(nums)-2;i>=0;i--)
        {
            while(!pq.empty() and !(pq.top().second >= i+1 and pq.top().second<=i+k))
                pq.pop();
            int val = pq.top().first;
            score = val + nums[i];
            pq.push({score,i});
        }
        
        
        return score;
    }
};