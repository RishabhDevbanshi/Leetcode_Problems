class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        sort(costs.begin(),costs.end(),[&](auto &a , auto &b){
            return a[0] - a[1] < b[0] - b[1];
        });
        
        // for(auto &val : costs)
        // {
        //     cout << val[0] << " " << val[1] << "\n";
        // }
        
        int tot = 0; 
        
        for(int i=0;i<size(costs)>>1;i++)
            tot += costs[i][0];
        
        for(int i=size(costs)>>1;i<size(costs);i++)
            tot += costs[i][1];
        
        return tot;
    }
};