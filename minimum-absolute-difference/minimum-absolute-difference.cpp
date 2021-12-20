class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minDiff = arr[1] - arr[0];
        
        for(int i=2;i<size(arr);i++)
        {
            minDiff = min(minDiff,arr[i]-arr[i-1]);
        }
        
        vector<vector<int>> res;
        
        for(int i=1;i<size(arr);i++)
        {
            if(arr[i] - arr[i-1] == minDiff)
                res.push_back({arr[i-1],arr[i]});
        }
        
        return res;
    }
};