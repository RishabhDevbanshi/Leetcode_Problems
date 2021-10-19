class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size());
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push({score[i],i});
        }
        
        int cnt = 0;
        while(!pq.empty())
        {
            pair<int,int> p = pq.top();
            pq.pop();
            cnt++;
            int idx = p.second;
            if(cnt == 1) res[idx] = "Gold Medal";
            else if(cnt == 2) res[idx] = "Silver Medal";
            else if(cnt == 3) res[idx] = "Bronze Medal";
            else res[idx] = to_string(cnt);
        }
        
        return res;
    }
};