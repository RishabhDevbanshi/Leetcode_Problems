class Solution {
    
    vector<vector<int>> dp;
    
    int f(string &str,int num,int len,int idx)
    {
        if(idx >= size(str))
            return 0;
        
        if(num <= 0)
        {
            int cnt = 0;
            for(int i=idx;i<size(str);i++)
                cnt += str[i] == '1';
            
            return dp[idx][num] = cnt;
        }
        
       if(dp[idx][num] != -1)
           return dp[idx][num];
        
        if(str[idx] == '0')
            return dp[idx][num] = f(str,num,len,idx+1);
        else
        {
            int op1 =  f(str,num-1,len,idx+len);
            int op2 = 1 + f(str,num,len,idx+1);
            
            return dp[idx][num] = min(op1,op2);
        }
    }
    
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        
        dp.resize(size(floor)+1,vector<int>(numCarpets+1,-1));
        
        return f(floor,numCarpets,carpetLen,0);
    }
};