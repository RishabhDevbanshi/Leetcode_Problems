class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        int start =0 ,end = n-1;
        while(start < end)
        {
            int val = arr[start] + arr[end];
            if(val == target) return {start+1,end+1};
            else if(val < target) start++;
            else end--;
        }
        
        return {};
    }
};