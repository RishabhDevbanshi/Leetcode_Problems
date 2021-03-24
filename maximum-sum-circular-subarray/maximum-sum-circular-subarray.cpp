class Solution {
public:
    int maxSumSubarray(vector<int>& arr)
    {
        int n = arr.size();
        int maxsum = INT_MIN;
        int currsum = 0;
        
        for(int i=0;i<n;i++)
        {
            currsum += arr[i];
            maxsum = max(currsum,maxsum);
            
            currsum = max(0,currsum);
        }
        
        return maxsum;
    }
    
    int minSumSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int minsum = INT_MAX;
        int currsum = 0;
        
        for(int i=0;i<n;i++)
        {
            currsum += arr[i];
            minsum = min(minsum,currsum);
            
            currsum = min(0,currsum);
        }
        
        return minsum;
    }
    
    int maxSubarraySumCircular(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        int mx = arr[0];
        bool flag = true;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] > 0) flag = false;
            sum += arr[i];
            mx = max(mx,arr[i]);
        }
        
        if(flag) return mx;
        
        int maxsum1 = maxSumSubarray(arr);
        int minsum = minSumSubarray(arr);
        
        cout<<maxsum1<<" "<<minsum;
        
        int maxsum2 = sum - minsum;
        
        return max(maxsum1,maxsum2);
    }
};