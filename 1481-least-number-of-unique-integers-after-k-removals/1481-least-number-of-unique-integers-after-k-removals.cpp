class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,int> mp;
        for(auto &val : arr)
            mp[val]++;
        for(auto it : mp)
            pq.push(it.second);
        
        int cnt = 0;
        
        while(!pq.empty() and cnt<k)
        {
            int x = pq.top(); pq.pop();
            x--;
            if(x) pq.push(x);
            cnt++;
        }
        
        return pq.size();
    }
};