class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        
        sort(arr.begin(),arr.end(),[](vector<int> a,vector<int> b){
            if(a[1] == b[1]) return a[0] < b[0];
            
            return a[1] < b[1];
        });
        
        int cnt = 0;
        int end = arr[0][1];
        for(int i=1;i<n;i++)
        {
            if(arr[i][0] >= end) end = arr[i][1];
            else cnt++;
        }
        
        return cnt;
    }
};