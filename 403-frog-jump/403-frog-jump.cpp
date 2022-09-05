class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        unordered_map<int,int> st;
        for(int i=0;i<size(stones);i++)
            st[stones[i]] = i;
        
        map<pair<int,int>,bool> dp;
        
        function<bool(int,int)> dfs = [&](int idx,int prev){
            if(idx == size(stones)-1)
              return true;
            
            if(dp.find({idx,prev}) != dp.end())
                return dp[{idx,prev}];
            
            bool ok = false;
            
            if(prev-1 > 0 and st.find(stones[idx]+prev-1) != st.end())
            {
                ok |= dfs(st[stones[idx]+prev-1],prev-1);
            }
            if(prev > 0 and st.find(stones[idx]+prev) != st.end())
            {
                ok |= dfs(st[stones[idx]+prev],prev);
            }
            if(prev + 1 > 0 and st.find(stones[idx]+prev+1) != st.end())
            {
                ok |= dfs(st[stones[idx]+prev+1],prev+1);
            }
            
            return dp[{idx,prev}] = ok;
        };
        
        return dfs(0,0);
    }
};