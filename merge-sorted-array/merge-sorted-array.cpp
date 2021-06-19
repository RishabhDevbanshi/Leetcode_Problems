class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        double gap = ceil(((double)m+n)/2);
        int j = 0;
        for(int i=m;i<m+n;i++) nums1[i] = nums2[j],++j;
        
        while(gap != 1)
        {
            int start = 0, end = start + gap;
            
            while(end < m+n)
            {
                // cout<<nums1[start]<<" "<<nums1[end]<<"\n";
                if(nums1[start] > nums1[end]) swap(nums1[start],nums1[end]);
                start++ , end++;
            }
            
            gap = ceil(gap/2);
        }
        
        for(int i=1;i<m+n;i++)
        {
            if(nums1[i] < nums1[i-1]) swap(nums1[i],nums1[i-1]);
        }
        
    }
};