class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long sum = 0 , x = 0;
        
        int reach = 0;
        
        for(int i=1;i<size(heights);i++)
        {
            if(heights[i] <= heights[i-1])
            {
                reach++;
                continue;
            }
            
            int diff = heights[i] - heights[i-1];
            sum += diff;
            pq.push(diff);
            x += diff;
            
            if(pq.size() > ladders)
                x -= pq.top() , pq.pop();
            
            if(sum - x > bricks)
                return i-1;
        }
        
        
        return size(heights)-1;
    }
};