class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        arr.push_back(val);
        mp[val] = size(arr)-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        int idx = mp[val];
        mp[arr.back()] = idx;
        swap(arr[idx],arr.back());
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int max = arr.size()-1 , min = 0;
        int range = max - min + 1;
        int num = rand() % range + min;
        return arr[num];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */