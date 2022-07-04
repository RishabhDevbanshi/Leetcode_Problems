class Solution {
public:
    int candy(vector<int>& ratings) {
        typedef pair<int,int> pi;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<size(ratings);i++)
        {
            pq.push({ratings[i],i});
        }
        
        vector<int> candy(size(ratings));
        int tot = 0;
        
        while(!pq.empty())
        {
            auto [val,idx] = pq.top(); pq.pop();
            int maxi = 0;
            if(idx>0 and ratings[idx-1] < ratings[idx]) maxi = candy[idx-1];
            if(idx+1<size(ratings) and ratings[idx+1] < ratings[idx]) maxi = max(maxi,candy[idx+1]);
            candy[idx] = maxi+1 , tot += maxi+1;
        }
        
        return tot;
    }
};