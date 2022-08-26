class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        set<pair<long double,pair<long double,long double>>> st;
        for(int i=0;i<size(arr)-1;i++)
        {
            long double x = arr[i];
            st.insert({x/arr.back(),{arr[i],size(arr)-1}});
        }
        
        // for(auto &it : st)
        // {
        //     cout << it.second.first << " " << arr[it.second.second] << "\n";
        // }
        
        // auto itt = *st.begin();
        // cout << itt.second.first << " " << arr[itt.second.second] << "\n";
        
        for(int j=0;j<k-1;j++)
        {
            auto beg = *st.begin(); st.erase(st.begin());
            auto val = beg.first;
            auto num = beg.second.first , idx = beg.second.second;
            if(idx > 0)
            {
                // cout << "here\n";
                idx--;
                if(arr[idx] == num) idx--;
                if(idx < 0) continue;
                // long double sec = 
                long double x = num / arr[idx];
                // cout << x << " " << num << " " << arr[idx] << "\n";
                st.insert({x,{num,idx}});
            }
            
            // for(auto &it : st)
            // {
            //     cout << "{ " << it.first << " " << it.second.first << " " << arr[it.second.second] << " } , ";
            // }
            // cout << "\n";
        }
        
        auto it = *st.begin();
        return {(int)it.second.first,(int)arr[it.second.second]};
    }
};