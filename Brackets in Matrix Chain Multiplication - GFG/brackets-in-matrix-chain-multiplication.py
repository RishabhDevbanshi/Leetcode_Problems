#User function Template for python3

class Solution:
    def matrixChainOrder(self, p, n):
        
        dp = {}
        
        def fun(i,j):
            if i==j:
                s=""
                ch = chr(64 + i)
                s = s + ch
                return [0,s]
            
            key = str(i) + "$" + str(j)
            
            if dp.get(key) != None:
                return dp[key]
            
            mini = 1e20
            s = ""
            for k in range(i,j):
                left = fun(i,k)
                right = fun(k+1,j)
                op = left[0] + right[0] + (p[i-1] * p[k] * p[j])
                if op < mini:
                    mini = op
                    s = "(" + left[1] + right[1] + ")"
            dp[key] =  [mini,s]
            return dp[key]
        
        return fun(1,n-1)[1];
        
        
        

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = input().split()
        for i in range(n):
            p[i] = int(p[i])
        
        ob = Solution()
        print(ob.matrixChainOrder(p, n))
# } Driver Code Ends