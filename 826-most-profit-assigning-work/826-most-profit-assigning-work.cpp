class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> arr(size(profit));
        for(int i=0;i<size(profit);i++)
        {
            arr[i] = {difficulty[i],profit[i]};
        }
        
        sort(arr.begin(),arr.end());
        int tot=0;
        int maxi=0;
        
        for(auto &[d,p] : arr)
        {
            maxi = max(maxi,p);
            p = maxi;
        }
        
        auto bs = [&](int tar){
            int start=0, end = size(arr)-1;
            int ans = -1;
            while(start <= end)
            {
                int mid = (start + end)>>1;
                if(arr[mid].first > tar)
                    end = mid-1;
                else
                {
                    ans = ans == -1 ? mid : max(ans,mid);
                    start = mid+1;
                }
            }
            
            return ans;
        };
        
        for(auto &ele : worker)
        {
            int idx = bs(ele);
            if(idx != -1)
                tot += arr[idx].second;
        }
        
        
        return tot;
    }
};