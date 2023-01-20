class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        set<vector<int>> st;
        
        
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
        };
        
        dfs(0,-1);
        
        for(auto &ele : st) res.push_back(ele);
        
        return res;
    }
};