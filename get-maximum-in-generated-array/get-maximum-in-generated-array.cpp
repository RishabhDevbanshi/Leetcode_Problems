class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        vector<int> arr(n+1);
        arr[0] = 0 , arr[1] = 1;
        int idx = 0;
        while(idx <= n)
        {
            int temp = 2*idx;
            if(temp > n) break;
            arr[temp] = arr[idx];
            temp++;
            if(temp > n) break;
            arr[temp] = arr[idx] + arr[idx+1];
            idx++;
        }
        
        
        return *max_element(arr.begin(),arr.end());
    }
};