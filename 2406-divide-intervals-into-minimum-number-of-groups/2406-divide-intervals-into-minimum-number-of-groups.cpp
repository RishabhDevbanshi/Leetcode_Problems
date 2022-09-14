class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());   
        
        int cnt=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto &v : intervals)
        {
            while(!pq.empty() and pq.top() < v[0])
                pq.pop();
            pq.push(v[1]);
            // cout << pq.top() << "\n";
            cnt = max<int>(cnt,size(pq));
        }
        
        
        return cnt;
        
    }
};