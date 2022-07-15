// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isKPartitionPossible(int nums[], int n, int k)
    {
         int sum = 0;
         for(int i=0;i<n;i++)
            sum += nums[i];
            
            if(sum%k)
                return false;
            
            sort(nums,nums+n,greater<int>());
            
            int req = sum/k;
            
            int vis = 0;
            
            function<bool(int ,int ,int)> dfs = [&](int i,int k,int curr){
                if(k == 1)
                    return true;
                
                if(i >= n)
                    return false;
                
                if(curr == req)
                {
                    return dfs(0,k-1,0);
                }
                
                for(int j=i;j<n;j++)
                {
                    int bit = (vis>>j)&1;
                    if(bit || curr + nums[j] > req)
                        continue;
                    
                    vis ^= (1<<j);
                    bool ok = dfs(j+1,k,curr + nums[j]);
                    if(ok)
                        return true;
                    vis ^= (1<<j);
                }
                
                
                return false;
            };
            
            return dfs(0,k,0);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends