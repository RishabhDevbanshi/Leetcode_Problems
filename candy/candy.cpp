#define ll long long
#define pi pair<int,int>

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int gift[n]; 
        memset(gift,0,sizeof(gift));
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({ratings[i],i});
        }
        
        int sum = 0;
        
        while(!pq.empty())
        {
            pi child = pq.top();
            pq.pop();
            
            int rank = child.first , idx = child.second;
            int l=0,r=0,lrank=1e5,rrank=1e5;
            
            if(idx-1 >= 0) l=gift[idx-1] , lrank = ratings[idx-1];
            if(idx+1 < n) r = gift[idx+1] , rrank = ratings[idx+1];
            
            if(rank>lrank && rank>rrank) gift[idx] = max(l,r) + 1;
            else if(rank>lrank) gift[idx] = l+1;
            else if(rank>rrank) gift[idx] = r+1;
            else gift[idx] = 1;
            
            if(gift[idx] == 0) gift[idx]++;
            
            sum += gift[idx];
        }
        
        return sum;
    }
};