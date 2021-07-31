class Solution {
    private int recur(int n,int i,int p,boolean flag)
    {
        if(i > n) return (int)1004;
        if(i == n) return 0;
        
        if(flag == true)
            return 1 + recur(n,i+p,p,false);
        
        return 1 + Math.min(recur(n,i+p,p,false),recur(n,i,i,true));
    }
    public int minSteps(int n) {
       int ans = recur(n,1,1,false);
        return n==1 ? ans : 1 + ans ;
    }
}