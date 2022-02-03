class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = size(nums1);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum = nums3[i] + nums4[j];
                mp[sum]++;
            }
        }
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int val = nums1[i] + nums2[j];
                int req = -val;
                
                if(mp.count(req))
                    cnt += mp[req];
            }
        }
        
        return cnt;
    }
};