class Solution {
public:
    int numWays(int steps, int arrLen) {
        
        const int mod = 1e9 + 7;
        vector<vector<long>> dp(steps/2+1,vector<long>(steps+1,-1));
        // map<pair<long,long>,long> mp;
        
        function<long(int,int)> dfs = [&](int idx,int key)->long{
            if(idx == 0 and key==0)
                return 1;
            if(key == 0 || idx < 0 || idx >= arrLen || idx>key)
                return 0;
            
            if(dp[idx][key] != -1)
                return dp[idx][key];
            
            // if(mp.find({idx,key}) != mp.end())
            //     return mp[{idx,key}];
            
            long op3 = dfs(idx,key-1)%mod;
            long op1 = dfs(idx+1,key-1)%mod;
            long op2 = dfs(idx-1,key-1)%mod;
            
            return dp[idx][key] = (op1 + op2 + op3)%mod;
        };
        
        return dfs(0,steps)%mod;
    }
};