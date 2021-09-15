class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n] , right[n];
        
        // left boundary
        int var = 0;
        for(int i=0;i<n;i++)
        {
            var = max(height[i],var);
            left[i] = var;
        }
        
        //right boundary
        var = 0;
        for(int i=n-1;i>=0;i--)
        {
            var = max(var,height[i]);
            right[i] = var;
        }
        
        //calculation of water
        var = 0;
        for(int i=0;i<n;i++)
        {
            var += min(left[i],right[i]) - height[i];
        }
        
        return var;
    }
};