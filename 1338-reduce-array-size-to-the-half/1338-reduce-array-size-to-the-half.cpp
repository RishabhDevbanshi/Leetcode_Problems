class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto &val : arr) mp[val]++;
        vector<int> freq;
        for(auto it : mp) freq.push_back(it.second);
        sort(freq.begin(),freq.end(),greater<int>());
        
        int tot=0;
        int n = size(arr);
        int curr = n;
        for(auto &val : freq)
        {
            // cout << val << " ";
            tot++, curr-=val;
            if(curr <= n/2) return tot;
        }
        
        
        return tot;
    }
};