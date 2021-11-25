class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums.front() , mn = nums.front() , r = nums.front();
        for(int i=1;i<nums.size();i++)
        {
            int val = nums[i];
            if(val < 0) swap(mx,mn);
            
            mx = max(val,val * mx);
            mn = min(val,val * mn);
            
            cout<<mx<<" "<<mn<<"\n";
            
            r = max(r,mx);
        }
        
        return r;
    }
};