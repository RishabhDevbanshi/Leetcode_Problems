// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    String s = sc.next();
                    Solution obj = new Solution();
                    System.out.println(obj.posIntSol(s));
                }
                
        }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    long factorial(int n){
        long f=1;
        for(int i=1;i<=n;i++)
        {
            f=f*i;
        }
        return f;
    }
    long posIntSol(String s)
    {
        int n=0;
        int equal_index=0;
        for(int j=0;j<s.length();j++)
        {
            if(s.charAt(j)=='+')
                n++;
            if(s.charAt(j)=='=')
                equal_index=j;
        }
    
        String number = s.substring(equal_index+1);
        int k = Integer.parseInt(number);
        k--;
        long numberator=1;
    
        for(int j=0; j < n; j++)
        {
            numberator = numberator*(k);
            k--;
        }
        long denominator=factorial(n);
        long ans = numberator/denominator;
        return ans;
    }
}