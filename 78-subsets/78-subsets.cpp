class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int sz = (1<<size(nums));
        
        for(int i=0;i<sz;i++)
        {
            vector<int> arr;
            for(int j=0;j<size(nums);j++)
            {
                int bit = (i>>j)&1;
                if(bit) arr.push_back(nums[j]);
            }
            
            ans.push_back(arr);
        }
        
        return ans;
    }
};