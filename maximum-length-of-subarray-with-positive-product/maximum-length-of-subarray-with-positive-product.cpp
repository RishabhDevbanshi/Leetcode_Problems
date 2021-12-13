class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int pos = 0 , neg = 0;
        int res = 0;
        
        for(auto &val : nums)
        {
            if(val == 0)
            {
                pos = 0 , neg = 0;
            }
            else if(val > 0)
            {
                pos++;
                neg = neg==0 ? 0 : neg+1;
            }
            else
            {
                int temp = pos;
                pos = neg==0 ? 0 : neg+1;
                neg = temp+1;
            }
            
            res = max(res,pos);
        }
        
        
        return res;
    }
};