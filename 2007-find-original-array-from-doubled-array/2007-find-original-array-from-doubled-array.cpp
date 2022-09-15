class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() & 1) 
        {
            vector<int> burrr;
                return burrr;
        }
        multiset<int> st;
        for(auto val : changed) st.insert(val);
        vector<int> arr;
        while(!st.empty())
        {
            auto it = st.end();
            it--;
            int val = *it;
            if(val & 1)
            {
                vector<int> burrr;
                return burrr;
            }
            
            auto del = st.find(val>>1);
            if(del == st.end())
            {
                vector<int> burrr;
                return burrr;
            }
            
            arr.push_back(val>>1);
            st.erase(it); st.erase(del);
        }
        
        if(arr.size() != changed.size()/2)
        {
            vector<int> burrr;
                return burrr;
        }
        
        return arr;
    }
};