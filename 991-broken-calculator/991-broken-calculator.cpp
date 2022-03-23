class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int op = 0;
        
        while(target > startValue)
        {
            if(target&1)
                target++;
            else 
                target = target>>1;
            
            op++;
        }
        
        return op + startValue - target;
    }
};