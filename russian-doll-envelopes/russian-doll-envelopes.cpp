class Solution {
public:
    static bool myCompare(vector<int> arr1,vector<int> arr2)
    {
        if(arr1[0] == arr2[0]) return arr1[1] > arr2[1];
        return arr1[0] < arr2[0];
    }
    
    int lb(int start,int end,int ele,vector<int> &arr)
    {
        int ans = 0;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(arr[mid] == ele) return mid;
            else if(arr[mid] > ele)
            {
                ans = mid;
                end = mid-1;
            }
            else start = mid + 1;
        }
        return ans;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),myCompare);
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<2;j++) cout<<envelopes[i][j]<<" ";
        //     cout<<"\n";
        // }
        
        vector<int> dp;
        dp.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++)
        {
            if(envelopes[i][1] > dp.back()) dp.push_back(envelopes[i][1]);
            else
            {
                int idx = lb(0,dp.size(),envelopes[i][1],dp);
                dp[idx] = envelopes[i][1];
            }
        }
        
        int ans = dp.size();
        dp.clear();
        
        return ans;
    }
};