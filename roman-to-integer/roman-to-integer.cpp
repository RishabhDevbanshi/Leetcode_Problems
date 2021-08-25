class Solution {
public:
    int romanToInt(string A) {
        unordered_map<char, int> mp = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
    
        int res = mp[A.back()];
        for(int i=A.size()-2;i>=0;i--)
        {
            if(mp[A[i]] < mp[A[i+1]]) res -= mp[A[i]];
            else res += mp[A[i]];
        }

        return res;
    }
};