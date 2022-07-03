class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int pos = 1, neg = 1;
        
        int maxi = 1;
        
        for(int i=1;i<size(nums);i++)
        {
            int npos=1 , nneg=1;
            if(nums[i] - nums[i-1] > 0) npos = neg+1;
            else if(nums[i] - nums[i-1] < 0) nneg = pos+1;
            
            pos = max(pos,npos) , neg = max(nneg,neg);
            maxi = max({maxi,pos,neg});
        }
        
        return maxi;
    }
};