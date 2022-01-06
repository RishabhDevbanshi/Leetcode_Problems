class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(1001);
        
        for(auto &tr : trips) arr[tr[1]] += tr[0] , arr[tr[2]] -= tr[0];
        for(int i=0;i<1001 and capacity >= 0;i++) capacity -= arr[i];
        
        return capacity >= 0;
        
    }
};