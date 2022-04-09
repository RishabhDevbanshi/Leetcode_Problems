class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        // vector<int> freq(mx+1);
        
        for(auto &val : nums)
            mp[val]++;
        
        typedef pair<int,int> pii;
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        for(auto &it : mp)
        {
            int i = it.first;
            pq.push({mp[i],i});
            
            if(size(pq) > k)
                pq.pop();
        }
        
        // vector<int> res;
        
        // freq.clear();
        vector<int> res;
        
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};