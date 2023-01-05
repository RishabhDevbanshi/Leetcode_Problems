class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(size(points) == 1) return 1;
        sort(points.begin(),points.end(),[&](auto &a,auto &b){
            // if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        int cnt = 1, prev = points[0][1];
        
        int n = size(points);
        
        for(int i=1;i<n;i++)
        {
            if(prev >= points[i][0]) continue;
            else cnt++ , prev = points[i][1];
        }
        
        return cnt;
    }
};