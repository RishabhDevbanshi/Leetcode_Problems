class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> st;
        vector<int> arr;
        
        function<void(int,int)> dfs = [&](int idx,int pidx){
            if(idx >= size(nums))
            {
                if(size(arr) > 1)
                    st.insert(arr);
                return;
            }
            
            dfs(idx+1,pidx);
            
            if(pidx == -1 or nums[idx] >= nums[pidx])
            {
                arr.push_back(nums[idx]);
                dfs(idx+1,idx);
                arr.pop_back();
            }
            
            return;
        };
        
        
        dfs(0,-1);
        
        for(auto v : st) res.push_back(v);
        
        return res;
    }
};