class Solution {
public:
    int findIntegers(int n) {
        vector<int> arr;
        while(n)
        {
            arr.push_back(n%2);
            n /= 2;
        }
        
        reverse(arr.begin(),arr.end());
        string str = "";
        
        for(auto &val : arr) str += '0' + val;
        // string str = to_string(n);
        
        int dp[size(str)][2][2][2];
        memset(dp,-1,sizeof dp);
        
        function<int(int,int,bool,bool)> dfs = [&](int idx,int prev,bool ok, bool zero)->int{
            if(idx == size(str))
                return 1;
            
            if(dp[idx][prev][ok][zero] != -1)
                return dp[idx][prev][ok][zero];
            
            int ways = 0;
            int LMT = ok ? str[idx]-'0' : 1;
            for(int i=0;i<=LMT;i++)
            {
                if(i==0 and zero)
                    ways += dfs(idx+1,i,false,true);
                else if(i==prev and prev==1)
                    continue;
                else if(ok and i==str[idx]-'0')
                    ways += dfs(idx+1,i,true,false);
                else 
                    ways += dfs(idx+1,i,false,false);
            }
            
            return dp[idx][prev][ok][zero] = ways;
        };
        
        
        return dfs(0,0,true,true);
    }
};