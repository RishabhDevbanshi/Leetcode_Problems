class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int,int>> arr;
        vector<int> res(size(queries));
        for(int i=0;i<size(queries);i++)
            arr.push_back({queries[i],i});
        
        sort(arr.begin(),arr.end());
        sort(items.begin(),items.end());
        
        int i=0 , maxi = 0;
        
        for(auto &[val,idx] : arr)
        {
            while(i<size(items) and items[i][0] <= val)
                maxi = max(items[i][1],maxi) , i++;
            // cout << i << " ";
            res[idx] = maxi;
        }
        
        return res;
    }
};