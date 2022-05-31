class Solution {
public:
    bool hasAllCodes(string s, int k) {
        bitset<20> bt;
        
        unordered_set<bitset<20>> st;
        
        int cnt = 0;
        
        for(int i=0;i<size(s);i++)
        {
            bt = bt<<1;
            bt[0] = s[i] - '0';
            bt[k] = 0;
            
            if(i >= k-1 and st.find(bt) == st.end()) 
                st.insert(bt) , cnt++;
        }
        
        
        return cnt == (1<<k);
    }
};