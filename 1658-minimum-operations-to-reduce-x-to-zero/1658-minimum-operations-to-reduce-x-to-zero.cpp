class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = size(nums);
        vector<int> suff(n);
        suff[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
            suff[i] = nums[i] + suff[i+1];
        if(suff[0] < x)
            return -1;
        
        int mini = INT_MAX;
        reverse(suff.begin(),suff.end());
        
        auto bs = [&](int low,int high,int req){
            while(low <= high)
            {
                int mid = (low + high) >> 1;
                // cout << suff[mid] << "\n";
                if(suff[mid] == req)
                    return mid;
                if(suff[mid] > req)
                    high = mid-1;
                else
                    low = mid+1;
            }
            
            return -1;
        };
        
        // for(auto &val : suff)
        //     cout << val << " ";
        // cout << "\n";
        
        int val = bs(0,n-1,x);
        // cout << val << "\n";
        if(val != -1)
            mini = min(mini,val+1);
        
        // cout << mini << "\n";
        
        int sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(sum == x)
                mini = min(mini,i+1);
            
            if(sum > x)
                break;
            
            int val = bs(0,n-i-2,x - sum);
            if(val != -1)
            {
                // cout << val <<  " ";
                mini = min(mini,val+1 + i+1);
            }
        }
        
        cout << mini << "\n";
        return mini == INT_MAX ? -1 : mini;
    }
};