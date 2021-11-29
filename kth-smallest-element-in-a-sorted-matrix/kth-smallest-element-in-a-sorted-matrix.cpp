// #define vi vector<int>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        typedef vector<int> vi;
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        for(int i=0;i<n;i++) pq.push({matrix[i][0],i,0});
        // cout<<pq.size();
        int cnt = 0;
        while(!pq.empty())
        {
            auto v = pq.top();
            // int x = 0,wt = 0,y=0;
            int wt = v[0] , x = v[1], y = v[2];
            pq.pop();
            cnt++;
            if(cnt == k) return wt;
            if(y+1<n)
                pq.push({matrix[x][y+1],x,y+1});
            // break;
        }
        
        return -1;
    }
};