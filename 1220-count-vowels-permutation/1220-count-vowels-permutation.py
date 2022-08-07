class Solution:
    def countVowelPermutation(self, n: int) -> int:
        a,e,i,o,u = 1,1,1,1,1
        mod = 1e9 + 7
        for _ in range(1,n):
            na,ne,ni,no,nu = (e+i+u)%mod , (a+i)%mod , (o+e)%mod, (i)%mod , (i+o)%mod
            a,e,i,o,u = na,ne,ni,no,nu
        return int((a+e+i+o+u)%mod)