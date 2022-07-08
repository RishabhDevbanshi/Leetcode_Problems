class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        
        int n = size(stoneValue);
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        function<int(int,int)> game = [&](int left,int right){
            if(left == right)
                return 0;
            
            if(dp[left][right] != -1)
                return  dp[left][right];
            
            int rightSum = 0 , leftSum = 0;
            for(int i=left;i<=right;i++)
                rightSum += stoneValue[i];
            
            int maxi = 0;
            
            for(int i=left;i<=right;i++)
            {
                rightSum -= stoneValue[i];
                leftSum += stoneValue[i];
                
                if(rightSum > leftSum)
                    maxi = max(maxi,leftSum + game(left,i));
                else if(leftSum > rightSum)
                    maxi = max(maxi,rightSum + game(i+1,right));
                else 
                    maxi = max({maxi,leftSum + game(left,i),rightSum + game(i+1,right)});
            }
            
            return dp[left][right] = maxi;
        };
        
        
        return game(0,size(stoneValue)-1);
    }
};