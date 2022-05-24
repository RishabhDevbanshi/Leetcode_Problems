class ThroneInheritance {
    unordered_map<string,vector<string>> mp;
    unordered_set<string> st;
    
    string king;
    
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);   
    }
    
    void death(string name) {
        st.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        
        vector<string> res;
        
        function<void(string &)> dfs = [&](string &node){
            
            if(st.find(node) == st.end())
                res.push_back(node);
            
            for(auto &child : mp[node])
                dfs(child);
        };
        
        dfs(king);
        
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */