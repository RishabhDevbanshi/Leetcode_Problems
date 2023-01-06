class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cnt=1;
        int end = points[0][1];
        for(auto &point : points)
        {
            if(point[0] <= end)
                end = min(end,point[1]);
            else
                cnt++ , end = point[1];
            // cout << point[0] << " " << point[1] << " " << end << "\n";

            // cout << end << ""
        }
        
        return cnt;
    }
};