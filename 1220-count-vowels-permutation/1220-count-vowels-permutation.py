class Solution:
    def countVowelPermutation(self, n: int) -> int:
        a,e,i,o,u,mod = 1,1,1,1,1,1e9 + 7
        for _ in range(1,n):
            a,e,i,o,u = (e+i+u)%mod , (a+i)%mod , (o+e)%mod, (i)%mod , (i+o)%mod
        return int((a+e+i+o+u)%mod)