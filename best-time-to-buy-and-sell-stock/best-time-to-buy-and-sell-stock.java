class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] greater = new int[n];
        
        greater[n-1] = prices[n-1];
        for(int i=n-2;i>=0;i--)
            greater[i] = Math.max(greater[i+1],prices[i]);
        
        int ans = 0;
        
        for(int i=0;i<n;i++) ans = Math.max(ans,greater[i] - prices[i]);
        
        return ans;
        
    }
}