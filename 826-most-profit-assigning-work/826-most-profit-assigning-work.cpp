class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> arr(size(profit));
        for(int i=0;i<size(profit);i++)
        {
            arr[i] = {difficulty[i],profit[i]};
        }
        
        int tot=0;
        
        sort(arr.begin(),arr.end());
        sort(worker.begin(),worker.end());
        
        int i=0 , best = 0;
        for(auto &val : worker)
        {
            while(i<size(arr) and arr[i].first<=val)
                best = max(best,arr[i++].second);
            tot += best;
        }
        
        
        return tot;
    }
};