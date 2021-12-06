class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int n = pos.size();
        int res = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(i == j) continue;
                int diff = abs(pos[i] - pos[j]);
                diff %= 2;
                // cout<<diff<<" ";
                cnt += diff;
            }
            // cout<<"\n";
            res = min(res,cnt);
        }
        
        return res;
    }
};