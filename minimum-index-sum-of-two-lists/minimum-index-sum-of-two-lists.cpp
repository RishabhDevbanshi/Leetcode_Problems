class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string,vector<int>> mp;
        int i=0;
        for(auto &str : list1) mp[str].push_back(i++);
        i=0;
        for(auto &str : list2) mp[str].push_back(i++);
        
        int maxSum = INT_MAX;
        for(auto &[key,value] : mp)
        {
            // cout<<key<<" -> ";
            // for(auto &ele : value) cout<<ele<<" "; cout<<endl;
            if(value.size() < 2) continue;
            int val = value[0] + value[1];
            if(val > maxSum) continue;
            else if(val == maxSum) res.push_back(key);
            else {
                res.clear();
                res.push_back(key);
                maxSum = val;
            }
        }
        
        return res;
    }
};