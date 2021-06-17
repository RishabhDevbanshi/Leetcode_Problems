class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> arr(n+1);
        
        for(int i=0;i<trust.size();i++)
        {
            int a = trust[i][0] , b = trust[i][1];
            arr[a].first++;
            arr[b].second++;
        }
        
        
        for(int i=0;i<n;i++)
        {
            // cout<<arr[i+1].first<<" "<<arr[i+1].second<<"\n";
            if(arr[i+1].first == 0 and arr[i+1].second == n-1) return i+1;
        }
        
        return -1;
    }
};