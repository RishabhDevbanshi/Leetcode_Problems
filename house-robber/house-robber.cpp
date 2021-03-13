class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int* arr = new int[4];
        arr[0] = nums[0]; //equivalent to inc
        arr[1] = 0; //equivalent to exc
        for(int i=1;i<nums.size();i++)
        {
            arr[2] = arr[1] + nums[i]; //equivalent to ninc
            arr[3] = max(arr[0],arr[1]);
            
            arr[0] = arr[2];
            arr[1] = arr[3];
        }
        
        int ans = max(arr[0],arr[1]);
        delete[] arr;
        
        return ans;
    }
};