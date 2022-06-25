class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int i=0;
        while(i<size(nums)-1)
        {
            if(nums[i] > nums[i+1])
            {
                // scenario 1
                bool ok;
                if(i==0 || nums[i-1] <= nums[i+1]) ok = true;
                else ok = false;
                if(ok)
                {
                    int j = i+1;
                    while(j < size(nums)-1)
                    {
                        if(nums[j] > nums[j+1])
                        {
                            ok = false;
                            break;
                        }
                        j++;
                    }
                    
                    if(ok) return true;
                }
                
                //scenario 2
                ok = true;
                nums[i+1] = nums[i];
                int j = i+1;
                while(j<size(nums)-1)
                {
                    if(nums[j] > nums[j+1])
                    {
                        ok = false;
                        break;
                    }
                    j++;
                }
                
                if(ok) return true;
                
                break;
            }
            i++;
        }
        
        return i == size(nums)-1 ? true : false;
    }
};