#define vi vector<int>
#define pi pair<int,int> 
#define fs first
#define sc second

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        auto comp = [&nums1,&nums2](pi a,pi b){
            return nums1[a.fs] + nums2[a.sc] > nums1[b.fs] + nums2[b.sc];
        };
        priority_queue<pi,vector<pi>,decltype(comp)> pq(comp);
        pq.push({0,0});
        int cnt = 0;
        while(!pq.empty() and cnt<k)
        {
            cnt++;
            pi p = pq.top();
            pq.pop();
            res.push_back({nums1[p.fs],nums2[p.sc]});
            if(p.fs + 1 < nums1.size())
                pq.push({p.fs + 1 , p.sc});
            if(p.fs==0 and p.sc + 1 < nums2.size())
                pq.push({p.fs,p.sc+1});
        }
        return res;
    }
};