class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++) arr[i] = {ages[i],scores[i]};
        sort(arr.begin(),arr.end(),[](auto a,auto b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        
        int lis[n];
        memset(lis,0,sizeof(lis));
        
        for(int i=0;i<n;i++)
        {
            int mx = 0;
            for(int j=0;j<i;j++)
            {
                if(arr[i].second >= arr[j].second)
                    mx = max(mx,lis[j]);
            }
            
            lis[i] = arr[i].second + mx;
        }
        
        return *max_element(lis,lis+n);
    }
};