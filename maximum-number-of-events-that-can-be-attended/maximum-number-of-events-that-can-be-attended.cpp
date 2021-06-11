class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int d = 1000000,ans = 0,i=0;
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int j=1;j<d;j++)
        {
            while(!pq.empty() and pq.top() < j)
            {
                pq.pop();
            }
            
            while(i<n and events[i][0] == j)
            {
                pq.push(events[i][1]);
                i++;
            }
            
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
        }
        
        return ans;
    }
};