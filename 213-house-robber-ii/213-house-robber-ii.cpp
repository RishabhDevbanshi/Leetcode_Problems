class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(size(nums) == 1)
            return  nums[0];
        
        auto fun = [&](int i,int j){
            int in=0,ex=0;
            for(int x=i;x<=j;x++)
            {
                int a=nums[x]+ex , b=max(in,ex);
                in=a,ex=b;
            }
            
            return  max(in,ex);
        };
        
        return max(fun(0,size(nums)-2),fun(1,size(nums)-1));
    }
};