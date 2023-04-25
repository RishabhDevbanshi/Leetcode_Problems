class SmallestInfiniteSet {
    set<int> st;
public:
    SmallestInfiniteSet() {
        for(int i=1;i<=4000;i++)
            st.insert(i);
    }
    
    int popSmallest() {
        int val = *st.begin();
        st.erase(st.begin());
        return val;
    }
    
    void addBack(int num) {
        if(st.find(num) == st.end())
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */