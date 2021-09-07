class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++) nums[i] *= -1;
        
        priority_queue<int> maxHeap;
        
        maxHeap.push(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            maxHeap.push(nums[i]);
            
            if(maxHeap.size() > k) maxHeap.pop();
        }
        
        return -1*maxHeap.top();
    }
};