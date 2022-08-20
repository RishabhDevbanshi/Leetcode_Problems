class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        
        string str = to_string(n);
        
        int dp[12][1024][2][2][2];
        memset(dp,-1,sizeof dp);
        
        function<int(int,int,bool,bool,bool)> dfs = [&](int idx,int vis,bool ok,bool zero,bool rep)->int{
              if(idx == size(str))
                  return !zero and rep;
            
               if(dp[idx][vis][ok][zero][rep] != -1)
                   return dp[idx][vis][ok][zero][rep];
            
              int LMT = ok ? str[idx]-'0' : 9;
              int ways = 0;
              for(int i=0;i<=LMT;i++)
              {
                  if(i==0 and zero)
                  {
                      ways += dfs(idx+1,0,false,true,false);
                      continue;
                  }
                  
                  int bit = (vis>>i) & 1;
                  bool nrep = rep || bit==1;
                  
                  if(bit == 0)
                      vis ^= 1<<i;
                  
                  if(ok and i == str[idx]-'0')
                      ways += dfs(idx+1,vis,true,false,nrep);
                  else
                      ways += dfs(idx+1,vis,false,false,nrep);
                  
                  if(bit == 0) 
                    vis ^= 1<<i;
              }
            
              return dp[idx][vis][ok][zero][rep] = ways;
        };
        
        
        return dfs(0,0,true,true,false);
    }
};