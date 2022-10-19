class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto &word : words)
            mp[word]++;
        priority_queue<pair<int,string>> pq;
        for(auto &it : mp)
        {
            pq.push({-it.second,it.first});
            if(size(pq) > k)
                pq.pop();
        }
        
        
        vector<string> ans;
        while(!pq.empty())
            ans.push_back(pq.top().second) , pq.pop();
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};