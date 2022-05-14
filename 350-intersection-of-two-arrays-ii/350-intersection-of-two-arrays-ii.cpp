class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0 , j=0 , n=nums1.size() , m = nums2.size();
        while(i<n and j<m)
        {
            if(nums1[i] == nums2[j])
            {
                    res.push_back(nums1[i]);
                i++ , j++;
            }
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        
        
        return res;
    }
};