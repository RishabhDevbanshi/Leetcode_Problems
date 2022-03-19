class FreqStack {
    set<vector<int>,greater<vector<int>>> st;
    unordered_map<int,vector<int>> mp;
    unordered_map<int,int> freq;
    
    int cnt = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        if(freq[val] > 0)
        {
            st.erase({freq[val],mp[val].back(),val});
        }
        
        ++freq[val]; mp[val].push_back(cnt++);
        st.insert({freq[val],mp[val].back(),val});
    }
    
    int pop() {
        
        auto v = *st.begin(); st.erase(st.begin());
        int num = v.back();
        --freq[num] , mp[num].pop_back();
        if(mp[num].size() > 0)
            st.insert({freq[num],mp[num].back(),num});
        
        return num;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */