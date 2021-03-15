class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int q = queries.length;
        
        int[] prefix  = new int[n+1];
        prefix[0] = 0;
        
        for(int i=0;i<n;i++) prefix[i+1] = prefix[i] ^ arr[i];
        
        int i=0;
        
        int[] ans = new int[q];
        
        while(i<q)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            
            r++; l++;
            
            ans[i] = prefix[r] ^ prefix[l-1];
            
            ++i;
        }
        
        return ans;
    }
}