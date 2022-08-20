class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        string str = to_string(n);
        
        digits.insert(digits.begin(),"0");
        // for(auto &val : digits) cout << val << " ";
        
        int dp[12][2][2];
        memset(dp,-1,sizeof dp);
        
        function<int(int,bool,bool)> dfs = [&](int idx,bool ok,bool zero)->int{
            if(idx == size(str))
                return !zero;
            
            if(dp[idx][ok][zero] != -1)
                return dp[idx][ok][zero];
            
            int LMT = ok ? str[idx] - '0' : 9;
            
            int ways = 0;
            
            for(auto &d : digits)
            {
                int dig = d[0] - '0';
                if(dig > LMT) break;
                if(dig == 0 and zero)
                    ways += dfs(idx+1,false,true);
                else if(dig == 0)
                    continue;
                else if(ok and dig == str[idx] - '0')
                    ways += dfs(idx+1,true,false);
                else
                    ways += dfs(idx+1,false,false);
            }
            return dp[idx][ok][zero] = ways;
        };
        
        return dfs(0,true,true);
    }
};