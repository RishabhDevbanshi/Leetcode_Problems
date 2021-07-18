class Solution {
    public int lengthOfLIS(int[] arr) {
        int n = arr.length;
        int[] lis = new int[n];
        for(int i=0;i<n;i++) lis[i] = 1;
        
        int i=1;
        while(i<n)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j] < arr[i] && lis[i] <= lis[j])
                    lis[i] = 1 + lis[j];
            }
            ++i;
        }
        
        int ans = 0;
        for(i=0;i<n;i++) ans = Integer.max(ans,lis[i]);
        
//         String str = "";
        
//         int curr = ans;
        
//         for(i=n-1;i>=0;i--)
//         {
//             if(lis[i] == curr)
//             {
//                 str += String.valueOf(arr[i]);
//                 str += " ";
//                 curr--;
//             }
//         }
        
//         System.out.println(str);
        
        return ans;
    }
}