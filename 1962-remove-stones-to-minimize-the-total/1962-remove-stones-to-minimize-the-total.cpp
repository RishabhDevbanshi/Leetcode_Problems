class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto &pile : piles)
            pq.push(pile);
        
        while(!pq.empty() and k)
        {
            --k;
            int top = pq.top(); pq.pop();
            top -= top/2;
            if(top)
                pq.push(top);
        }
        
        int sum = 0;
        while(!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            sum += top;
        }
        
        return sum;
    }
};