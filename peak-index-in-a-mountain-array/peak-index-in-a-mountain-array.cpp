class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0;
        for(int i=1;i<size(arr);i++)
        {
            if(arr[i] <= arr[i-1]) return i-1;
        }
        return -1;
    }
};