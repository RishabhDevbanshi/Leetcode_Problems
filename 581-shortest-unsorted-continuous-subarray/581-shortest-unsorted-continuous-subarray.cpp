class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> tmp = nums;
        sort(tmp.begin(),tmp.end());
        
        int start = -1 , end = -1;
        for(int i=0;i<size(nums);i++)
        {
            if(nums[i] != tmp[i])
            {
                if(start == -1)
                    start = end = i;
                else 
                    end = i;
            }
        }
        
        return start == -1 ? 0 :  end - start + 1;
    }
};