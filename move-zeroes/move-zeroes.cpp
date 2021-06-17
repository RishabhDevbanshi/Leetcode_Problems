class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1) return;
        
        int ele = *(nums.begin());
        nums.erase(nums.begin());
        
        moveZeroes(nums);
        
        if(ele == 0) nums.push_back(ele);
        else nums.insert(nums.begin(),ele);
    }
};