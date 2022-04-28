// { Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String input_line[] = read.readLine().trim().split("\\s+");
            int N = Integer.parseInt(input_line[0]);
            int K = Integer.parseInt(input_line[1]);
            input_line = read.readLine().trim().split("\\s+");
            int candies[]= new int[N];
            for(int i = 0; i < N; i++)
                candies[i] = Integer.parseInt(input_line[i]);

            Solution ob = new Solution();
            ArrayList<Integer> cost = ob.candyStore(candies,N,K);
            System.out.println(cost.get(0)+" "+cost.get(1));
        }
    }
}
// } Driver Code Ends


//User function Template for Java


class Solution{
    static ArrayList<Integer> candyStore(int candies[],int N,int k){
        Arrays.sort(candies);
        int a1=0,count1=0,i=0,a2=0,j=N-1,count2=0;
        while(count1<N || count2<N){
            a1=a1+candies[i];
            count1=count1+k+1;
            i++;
            a2=a2+candies[j];
            count2=count2+k+1;
            j--;
        }
        ArrayList<Integer> res=new ArrayList<>();
        res.add(a1);
        res.add(a2);
        return res;
    }
}