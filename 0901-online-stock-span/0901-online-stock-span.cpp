class StockSpanner {
    stack<pair<int,int>> st;
    int idx = 0;
public:
    StockSpanner() {
        while(!st.empty()) st.pop();
    }
    
    int next(int price) {
        idx++;
        while(!st.empty() and st.top().second <= price)
            st.pop();
        
        int ans = st.empty() ? idx : idx - st.top().first;
        // idx++;
        st.push({idx,price});
        
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */