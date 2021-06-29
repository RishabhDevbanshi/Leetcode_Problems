class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        
        sort(points.begin(),points.end(),[](auto a ,auto b){
            if(a[1] == b[1]) return a[0] < b[0];
            
            return a[1] < b[1];
        });
        
        int cnt = 1 , end = points[0][1];
        
        for(int i=1;i<n;i++)
        {
            if(points[i][0] <= end)
            {
                end = min(end,points[i][1]);
            }
            else
            {
                cnt++;
                end = points[i][1];
            }
        }
        
        return cnt;
    }
};