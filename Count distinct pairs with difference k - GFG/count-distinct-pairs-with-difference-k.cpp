// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    int i=0,cnt=0,j=1;

           sort(nums.begin(),nums.end());
        //   for(auto &val : nums)
        //     cout << val << " ";
        //     cout<<"\n";
        
          while(j<nums.size()){
        
              if(nums[j]-nums[i]<k){
        
                   j++;
            
               }
        
               else if(nums[j]-nums[i]>k){
            
                  i++;
            
               }
            
               else{
                    // cout << i << " " << nums[i] << " " << j << " " << nums[j] << "\n";
                   int a=nums[i],b=nums[j],c=0,d=0;
                   
                   if(i ==j)
                    {
                        j++;
                        continue;
                    }
            
                   if(k>0){
            
                       while(nums[i]==a){
            
                           c=1;
            
                           i++;
            
                       }
            
                       while(nums[j]==b){
            
                           d=1;
            
                           j++;
            
                       }
            
                       cnt+=c*d;
            
                       
            
                   }
            
                   else{
            
                       while(nums[i]==a){
            
                           c=2;
            
                           i++;
            
                           j++;
            
                       }
            
                       cnt+=c*(c-1)/2;
            
                   }
            
                   
            
               }
        
        }
        
        return cnt;
        

	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends