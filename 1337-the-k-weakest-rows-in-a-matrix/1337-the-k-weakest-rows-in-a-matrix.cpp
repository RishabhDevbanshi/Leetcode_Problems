class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>> pq;
        
        auto getStrength = [&](int i){
                auto it = lower_bound(mat[i].begin(),mat[i].end(),0,greater<int>()) 
                    - mat[i].begin();
            
            return it;
        };
        
        for(int i=0;i<mat.size();i++)
        {
            int strength = getStrength(i);
            // cout << strength << " ";
            pq.insert({strength,i});
            
            if(pq.size() > k)
                pq.erase(--pq.end());
            
        }
        
        vector<int> res(k);
        
        int i=0;
        
        for(auto &val : pq)
            res[i++] = val.second;
        
        return res;
    }
};