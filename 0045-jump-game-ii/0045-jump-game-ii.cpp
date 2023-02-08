class Solution {
public:
    int jump(vector<int>& nums) {
        int cr = 0 , mr = 0, jumps = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i + nums[i] > mr) mr = i + nums[i];
            
            if(i == cr)
            {
                jumps++ , cr = mr;
            }
        }
        
        return jumps;
    }
};