class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto fun = [&](int x){
            vector<int> cnt(10);
            while(x)
            {
                cnt[x%10]++;
                x/=10;
            }
            
            return cnt;
        };
        
        vector<int> arr = fun(n);
        
        for(int i=1;i<=(int)1e9;i*=2)
        {
            if(fun(i) == arr)
                return true;
        }
        
        return false;
    }
};