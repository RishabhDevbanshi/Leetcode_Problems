class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool zero = false , one = false;
        
        bool ok = true;
        
        while(n)
        {
            int bit = n%2;
            n = n>>1;
            // cout << bit << "\n";
            // cout << one << " " << zero << "\n";
            if(ok)
            {
                if(bit) one = true;
                else zero = true;
                ok = false;
            }
            else
            {
                if(bit)
                {
                    if(one)
                        return false;
                    else 
                        one = true , zero = false;
                }
                else 
                {
                    if(zero)
                        return false;
                    else
                        zero = true, one = false;
                }
            }
        }
        
        return  true;
    }
};