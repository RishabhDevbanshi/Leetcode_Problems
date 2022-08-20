class Solution {
public:
    int countSpecialNumbers(int n) {
        
        auto count = [&](int dig){
            long ans = 9; dig--;
            long rem = 9;
            while(dig) ans *= rem , rem-- , dig--;
            return ans;
        };
        string num = to_string(n);
        long num_dig = size(num);
        
        // map<pair<bool,pair<long,long>>,long> mp;
        long dp[2][11][1024];
        memset(dp,-1,sizeof dp);
        
        function<long(long,long,long)> dfs = [&](long idx,bool ok,long vis)->long{
            if(idx == size(num))
                return 1;
            if(dp[ok][idx][vis] != -1)
                return dp[ok][idx][vis];
            // if(mp.find({ok,{idx,vis}}) != mp.end())
                // return mp[{ok,{idx,vis}}];
            long LMT = ok ? num[idx] - '0' : 9;
            long ways = 0;
            for(int i=0;i<=LMT;i++)
            {
                if(idx == 0 and i == 0) continue;
                if((vis>>i)&1) continue;
                vis ^= 1<<i;
                if(ok and i == num[idx] - '0')
                {
                    ways += dfs(idx+1,true,vis);
                }
                else
                {
                    ways += dfs(idx+1,false,vis);
                }
                
                vis ^= 1<<i;
            }
            
            return dp[ok][idx][vis] = ways;
        };
        
        long tot = 0;
        for(int i=1;i<num_dig;i++) tot += count(i);
        tot += dfs(0,1,0);
        
        return tot;
    }
};