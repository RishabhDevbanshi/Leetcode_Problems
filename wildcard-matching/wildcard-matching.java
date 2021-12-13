class Solution {
    
    private boolean recur(String s,String p,int a,int b,int[][] dp)
    {
        if(b == p.length())
        {
            return a == s.length();
        }
        
        if(dp[a][b] != -1)
            return dp[a][b] == 1;
        
        if(a < s.length() && (s.charAt(a) == p.charAt(b) || p.charAt(b) == '?'))
        {
            boolean flag = recur(s,p,a+1,b+1,dp);
            dp[a][b] = flag == true ? 1 : 0;
            return flag;
        }
        if(p.charAt(b) == '*')
        {
            for(int i=a;i<=s.length();i++)
            {
                if(recur(s,p,i,b+1,dp) == true)
                {
                    dp[a][b] = 1;
                    return true;
                }
            }
            
            dp[a][b] = 0;
            return false;
        }
        
        dp[a][b] = 0;
        return false;
    }
    
    
    public boolean isMatch(String s, String p) {
        // int a = s.length
        int[][] dp = new int[s.length()+1][p.length()+1];
        for(int i=0;i<=s.length();i++)
        {
            for(int j=0;j<=p.length();j++)
                dp[i][j] = -1;
        }
        
        return recur(s,p,0,0,dp);
    }
}