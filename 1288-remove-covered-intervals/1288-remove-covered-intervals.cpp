class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        if(size(intervals) == 1)
            return 1;
        
        sort(intervals.begin(),intervals.end(),[&](auto &a,auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });
        
        int prev_start = intervals[0][0] , prev_end = intervals[0][1];
        
        int cnt = 1;
        for(int i=1;i<size(intervals);i++)
        {
            if(prev_start <= intervals[i][0] and intervals[i][1] <= prev_end)
            {
                // cout<<prev_start<<" "<<prev_end<<"\n";
                continue;
            }
            else
                prev_start = intervals[i][0] , prev_end = intervals[i][1] , cnt++;
        }
        
        return cnt;
    }
};