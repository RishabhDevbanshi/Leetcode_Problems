class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long> prev(5,1);
            
        const int mod = 1e9 + 7;
        
        long ans = 5;
        
        for(int i=1;i<n;i++)
        {
            vector<long> curr(5);
            
            curr[0] = (prev[1] + prev[2] + prev[4])%mod;
            curr[1] = (prev[0] + prev[2])%mod;
            curr[2] = (prev[1] + prev[3])%mod;
            curr[3] = (prev[2])%mod;
            curr[4] = (prev[2] + prev[3])%mod;
            
            prev = curr;
        }
        
        return accumulate(prev.begin(),prev.end(),0LL)%mod;        
    }
};