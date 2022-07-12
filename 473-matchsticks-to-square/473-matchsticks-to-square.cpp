class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
       int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(size(matchsticks) < 4 || sum % 4 != 0)
            return false;
        
        int bit_dp = 0;
        
        int req = sum/4;
        
        function<bool(int,int,int)> dfs = [&](int sum,int num,int i){
            if(num == 1)
                return true;
            
            if(sum == req)
                return dfs(0,num-1,0);
            
            for(int j=i;j<size(matchsticks);j++)
            {
                int bit = (bit_dp>>j)&1;
                if(bit || sum+matchsticks[j]>req)
                    continue;
                bit_dp = bit_dp xor (1<<j);
                bool ok = dfs(sum+matchsticks[j],num,j+1);
                
                if(ok)
                    return true;
                
                bit_dp = bit_dp xor (1<<j);
            }
            
            return false;
        };
        
        return dfs(0,4,0);
    }
};