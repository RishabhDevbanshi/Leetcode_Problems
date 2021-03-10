#define pi pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        priority_queue<pi,vector<pi>,greater<pi>> minHeap;
        
        for(int i=0;i<n;i++) mp[nums[i]]++;
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            minHeap.push({it->second,it->first});
            
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        
        vector<int> arr;
        while(!minHeap.empty())
        {
            arr.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return arr;
    }
};