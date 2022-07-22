class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr(size(ages));
        int maxi = 0;
        
        for(int i=0;i<size(ages);i++)
        {
            arr[i] = {ages[i],scores[i]};
        }
        
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });
        
        vector<int> dp(size(ages));
        
        for(int i=0;i<size(ages);i++)
        {
            int maxi = 0;
            for(int j=0;j<i;j++)
            {
                if(arr[i].second >= arr[j].second)
                    maxi = max(maxi,dp[j]);
            }
            
            dp[i] = maxi + arr[i].second;
        }
        
        
        return *max_element(dp.begin(),dp.end());
    }
};