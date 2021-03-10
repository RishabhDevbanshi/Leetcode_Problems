class Solution {
public:
    #define pi pair<int,vector<int>>
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> arr;
        priority_queue<pi> maxHeap;
        
        int n = points.size();
        for(int i=0;i<n;i++)
        {
            int dist=0;
            for(auto ele : points[i]) dist += ele*ele;
            maxHeap.push({dist,points[i]});
            
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        
        while(!maxHeap.empty())
        {
            arr.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return arr;
    }
};