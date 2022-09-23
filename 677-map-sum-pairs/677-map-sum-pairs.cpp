struct node{
    node *child[26];
    int times;
    node()
    {
        for(int i=0;i<26;i++)
            child[i] = nullptr;
        times=0;
    }
};

class MapSum {
    node *root;
    unordered_map<string,int> mp;
public:
    MapSum() {
        root = new node();
    }
    
    void insert(string key, int val) {
        auto tmp = root;
        for(auto &ch : key)
        {
            if(!tmp->child[ch - 'a'])
                tmp->child[ch - 'a'] = new node();
            tmp = tmp->child[ch - 'a'];
            tmp->times += val;
            if(mp.find(key) != mp.end())
                tmp->times -= mp[key];
        }
        mp[key] = val;
    }
    
    int sum(string prefix) {
        auto tmp = root;
        for(auto &ch : prefix)
        {
            if(!tmp->child[ch - 'a'])
                return 0;
            tmp = tmp->child[ch - 'a'];
        }
        
        return tmp->times;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */