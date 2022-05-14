class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        mp[n]++;
        while(n != 1)
        {
            int tmp = 0;
            while(n)
            {
                int dig = n%10;
                tmp += dig*dig;
                n /= 10;
            }
            
            n = tmp;
            if(mp.count(n))
                return false;
            mp[n]++;
        }
        
        return true;
    }
};