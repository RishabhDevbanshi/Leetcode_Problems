#define ull unsigned long long

class Solution {
public:
    int nthUglyNumber(int n) {
        set<ull> st;
        
        st.insert(1);
        
        int cnt = 0;
        
        while(!st.empty())
        {
            ull val = *st.begin();
            st.erase(st.begin());
            cnt++;
            // cout<<val<<" ";
            
            if(cnt == n) return val;
            
            // if(val > 10006) continue;
            
            st.insert(val * 2);
            st.insert(val * 3);
            st.insert(val * 5);
            
            // for(auto &ele : st) cout<<ele<<" ";
            // cout<<"\n";
            
        }
        
        return -1;
    }
};