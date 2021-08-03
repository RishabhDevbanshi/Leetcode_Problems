class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> arr;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        arr.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++)
        {
            if(arr.back()[1] >= intervals[i][0])
            {
                arr.back()[1] = max(arr.back()[1],intervals[i][1]);
            }
            else
            {
                arr.push_back(intervals[i]);
            }
        }
        
        return arr;
    }
};