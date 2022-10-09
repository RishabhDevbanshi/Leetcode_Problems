class TimeMap {
    unordered_map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int start = 0 , end = size(mp[key])-1;
        
        int idx = -1;
        
        while(start <= end)
        {
            int mid = (start + end)>>1;
            if(mp[key][mid].first == timestamp)
                return mp[key][mid].second;
            else if(mp[key][mid].first < timestamp)
                idx = mid , start = mid+1;
            else
                end = mid - 1;
                
        }
        
        return idx == -1 ? "" : mp[key][idx].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */