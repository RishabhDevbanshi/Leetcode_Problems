#define ll long long

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<ll> st;
        int l = 0;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
            // cout<<"Set : "<<st.size()<<" = ";
            // for(auto &val : st) cout<<val<<" ";
            // cout<<"\n";
            // int n = st.size();
            if(i - l > k)
            {
                st.erase(st.find(nums[l]));
                ++l;
            }
            if(st.size() == 1) continue;
            auto it = st.find(nums[i]);
            if(it == st.begin())
            {
                auto r = it; ++r;
                // cout<<"right : ";
                // for(auto x : st) cout<<x<<" ";
                // cout<<"\n";
                // cout<<*it<<" "<<*r<<"\n";
                ll val = abs((*it) - (*r));
                if(val <= t) return true;
            }
            else if(it == --st.end())
            {
                auto l = it; --l;
                // cout<<"left : ";
                // cout<<*it<<" "<<*l<<"\n";
                ll val = abs((*it) - (*l));
                if(val <= t) return true;
            }
            else
            {
                auto l=it , r=it;
                --l ; ++r;
                // cout<<"right : "<<*it<<" "<<*r<<"\n";
                // cout<<"left : "<<*it<<" "<<*l<<"\n";
                ll val1 = abs((*it) - (*l)) , val2 = abs((*it) - (*r));
                if(val1<=t || val2<=t) return true;
            }
        }
        
        return false;
    }
};